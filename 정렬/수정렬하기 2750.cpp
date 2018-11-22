#include<stdio.h>
/*
수 정렬하기 2750번
문제 :
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력 :
첫째 줄에 수의 개수 N(1<=N<=1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다.
이 수는 절대값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
*/

//선택, 버블, 삽입 등으로 풀면 풀림

int array[1001];//알고리즘 문제 풀경우 데이터갯수에 1을 더한것을 하는것이 좋다.

int main() {
	int number, i, j, min, index, temp;
	scanf("%d", &number);
	for (i = 0; i < number; i++) {
		scanf("%d", &array[i]);
	}

	for (i = 0; i < number; i++) {
		min = 1001;
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
		printf("%d\n", array[i]);
	}
	return 0;
}