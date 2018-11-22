#include <stdio.h>
//������
/*
������ : Ư���� ���� �������� ū���ڿ� ���� ���ڸ� ������ ���(���ذ� ����(Pivot), !!��������!!)
<������������ ���� �ð����⵵�� �پ��>
��� �ð� ���⵵ : O(N*logN)
�־� �ð� ���⵵ : O(N*N)  ==>�̹� ���ĵ� ������ �����ϴ� ��� ���������� Ư¡�� ������ ���� �����Ƿ� �־��� �ð��� �ɸ�
*/


int number = 10;
int data[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void show() {
	int i;
	/*for ( i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}*/
}
void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	} // start==end ��쿡�� ���Ұ� 1���̹Ƿ� �ٷ� ��ȯ
	int i = start + 1;
	int j = end;
	int temp;
	int key = start; // ���� Ű���� ù���ҷ� ��´�

	while (i <= j) {//i�� j�� ������������ �ݺ�
		while (data[i] <= data[key] && i<=end) {//->�������� ����Ͽ� key�� ���Һ��� ū���� ã��
			i++;
		}
		while (data[j] >= data[key] && j > start) {//<--���������� ����Ͽ� key�� ���Һ��� �������� ã��
			j--;
		}

		if (i > j) {//������ ���!!!!!
			temp = data[i];
			data[j] = data[key];
			data[key] = temp;
		}
		else { // �������� �ʾҴٸ� i�� j�� ��ü 
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
		//����Լ� ȣ��  ���� ����
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}


int main(void) {
	quickSort(data, 0, number - 1);
	show();
	

	return 0;
}