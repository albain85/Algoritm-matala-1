#include <iostream>
#include <stack>
#include <math.h>
#include <time.h>

using namespace std;

typedef struct data {
	int num;
	stack<int> s;
}Data;

void ex1(int * arr, int length);
void ex2();
void swap(int * a, int * b);
int minMax(int * a, int length);
Data rec(Data * sArr, int length );


void main() {
	double length = 5;
	int arr[5] = {1,2,2,2,5};

	ex1(arr, length);
	
}

void ex1(int * arr,int length) {
	int max1 = 0 , j = 0 , arrLength = ceil(length / (double)2);
	Data *s = new Data[arrLength];
	int max2 = 0;
	Data max;
	//for (int i = 0; i < length; i++)
	//	s[i].num = arr[i];
	for (int i = 0; i < length; i = i + 2)
		if (arr[i] >= arr[i + 1]) {
			s[j].num = arr[i];
			s[j].s.push(arr[i + 1]);
			j++;
		}
		else{
			s[j].num = arr[i + 1];
			s[j].s.push(arr[i]);
			j++;
		}
		s[arrLength - 1].num = arr[length - 1];
	max = rec(s, ceil(length/(double)2));  //length changes
	max1 = max.num;
	while (!max.s.empty()) {
		if (max2 < max.s.top())
			max2 = max.s.top();
		max.s.pop();
	}
	cout << "max1: " << max1 << endl;
	cout << "max2: " << max2 << endl;
};

Data rec(Data * sArr, int length ) {

	int j = 0 , arrLength = ceil(length / (double)2);
	if (length == 1) 
		return sArr[0];
	Data *temp = new Data[arrLength];
	if (!(length / 2 == 0)) {	// odd vs even
		temp[arrLength - 1].num = sArr[length - 1].num;	//last array room 
		while (!(sArr[length - 1].s.empty())) {
			temp[arrLength - 1].s.push(sArr[length - 1].s.top());
			sArr[length - 1].s.pop();
		}
	}
	//else
	//	temp[length / 2].num = 0;

	for (int i = 0; i < length - 1; i = i + 2)
			if (sArr[i].num >= sArr[i + 1].num) {
				temp[j].num = sArr[i].num;
				while (!sArr[i].s.empty()) {
					temp[j].s.push(sArr[i].s.top());
					sArr[i].s.pop();
				}
				temp[j].s.push(sArr[i + 1].num);
				j++;
			}
			else {
				temp[j].num = sArr[i + 1].num;
				while (!sArr[i + 1].s.empty()) {
					temp[j].s.push(sArr[i + 1].s.top());
					sArr[i + 1].s.pop();
				}
				temp[j].s.push(sArr[i].num);
				j++;
			}
		
		return  rec(temp, ceil(length /(double)2));
}

void ex2(){
	int r;
	int length = 1000, numArr = 100000;
	int *arr = new int[length];
	int sum = 0;

	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = i + 1;

	for (int j = 0; j < numArr; j++) {
		for (int i = 0; i < length; i++)
		{
			r = rand() % 100;
			swap(arr[i], arr[r]);
			//cout << arr[i] << endl;
		}
		sum += minMax(arr, length);
	}
	sum = sum / numArr;
	cout << "sum: " << sum << endl;


}

int minMax(int * a , int length) {

	int min = a[1];
	int max = min;
	int count = 0;

	for (int i = 0; i < length; i++)
		if (a[i] < min) {
			min = a[i];
			count++;
		}
		else if (a[i] > max) {
			max = a[i];
			count++;
		}
		//cout << "maximum:" << max << endl;
		//cout << "minimum:" << min << endl;
		return count;
}

void swap(int * a , int * b) {
	int * temp;
	temp = a;
	a = b;
	b = temp;

}