#include<stdio.h>
/*
수 정렬하기 2752번
문제 :
동규는 세수를 하다가 정렬이 하고싶어졌다.
숫자 세 개를 생각한 뒤에, 이를 오름차순으로 정렬하고 싶어 졌다.
숫자 세 개가 주어졌을 때, 가장 작은 수, 그 다음 수, 가장 큰 수를 출력하는 프로그램을 작성하시오.

입력 :
숫자 세 개가 주어진다. 이 숫자는 1보다 크거나 같고, 1,000,000보다 작거나 같다.
이 숫자는 모두 다르다.
*/

//선택, 버블, 삽입 등으로 풀면 풀림

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