#include<stdio.h>
/*
�� �����ϱ� 2752��
���� :
���Դ� ������ �ϴٰ� ������ �ϰ�;�����.
���� �� ���� ������ �ڿ�, �̸� ������������ �����ϰ� �;� ����.
���� �� ���� �־����� ��, ���� ���� ��, �� ���� ��, ���� ū ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է� :
���� �� ���� �־�����. �� ���ڴ� 1���� ũ�ų� ����, 1,000,000���� �۰ų� ����.
�� ���ڴ� ��� �ٸ���.
*/

//����, ����, ���� ������ Ǯ�� Ǯ��

int array[3];

int main() {
	int number, i, j, min, index, temp;
	number = 3;
	for (i = 0; i < number; i++) {
		scanf("%d", &array[i]);
	}

	for (i = 0; i < number; i++) {
		min = 1000001;
		for (j = i; j < number; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}

	for (i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}