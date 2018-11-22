#include<iostream>
using namespace std;
//선택정렬
/*
선택정렬 : 가장 작은것을 가장 앞에 보내기
시간 복잡도 : O(N*N)
*/
void main() {

	//내가 생각한 정렬방법
	int i, j, temp, min, index;
	int array[10] = { 1,5,2,9,3,6,7,4,8,10 };
	int array1[10] = { 1,5,2,9,3,6,7,4,8,10 };
	for (i = 0; i < 10; i++) {
		for (j = i+1; j < 10; j++) {
			if (array[i] > array[j]) {//스와핑
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	for (int k : array) {
		cout << k << " ";
	}
	cout << endl;
	//////////////////////////////////////////////////////////
	//선택정렬 
	for (i = 0; i < 10; i++) {
		min = 999;
		for (j = i; j < 10; j++) {
			if (min > array1[j]) {
				min = array1[j];
				index = j;
			}
		}
		temp = array1[i];//스와핑
		array1[i] = array1[index];
		array1[index] = temp;
	}

	for (int k : array1) {
		cout << k << " ";
	}
}