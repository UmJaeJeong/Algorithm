#include<iostream>
using namespace std;
//��������
/*
�������� : ���� �������� ���� �տ� ������
�ð� ���⵵ : O(N*N)
*/
void main() {

	//���� ������ ���Ĺ��
	int i, j, temp, min, index;
	int array[10] = { 1,5,2,9,3,6,7,4,8,10 };
	int array1[10] = { 1,5,2,9,3,6,7,4,8,10 };
	for (i = 0; i < 10; i++) {
		for (j = i+1; j < 10; j++) {
			if (array[i] > array[j]) {//������
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
	//�������� 
	for (i = 0; i < 10; i++) {
		min = 999;
		for (j = i; j < 10; j++) {
			if (min > array1[j]) {
				min = array1[j];
				index = j;
			}
		}
		temp = array1[i];//������
		array1[i] = array1[index];
		array1[index] = temp;
	}

	for (int k : array1) {
		cout << k << " ";
	}
}