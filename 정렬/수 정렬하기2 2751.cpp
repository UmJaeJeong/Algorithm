#include<stdio.h>
#include<algorithm>
/*
수 정렬하기2 2751번
문제 :
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력 :
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 
이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.
*/

//!!!N의 갯수가 100만개 이상일 경우에는 항상 O(N*logN)로 풀어야하기 떄문에 퀵정렬로 풀어야한다.
//퀵정렬, 병합정렬, 힙정렬을 사용 
//최악의 경우가 있기때문에 병합정렬이나 힙정렬을 사용하는것이 좋음

int number, data[1000000];

int main(void) {
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	std::sort(data, data + number);
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}