#include <stdio.h>
//퀵정렬
/*
퀵정렬 : 특정한 값을 기준으로 큰숫자와 작은 숫자를 나누는 방법(기준값 존재(Pivot), !!분할정복!!)
<분할정복으로 인해 시간복잡도가 줄어듬>
평균 시간 복잡도 : O(N*logN)
최악 시간 복잡도 : O(N*N)  ==>이미 정렬된 값들을 정렬하는 경우 분할정복의 특징인 분할이 되지 않으므로 최악의 시간이 걸림
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
	} // start==end 경우에는 원소가 1개이므로 바로 반환
	int i = start + 1;
	int j = end;
	int temp;
	int key = start; // 보통 키값을 첫원소로 잡는다

	while (i <= j) {//i와 j가 엇갈릴때까지 반복
		while (data[i] <= data[key] && i<=end) {//->왼쪽으로 출발하여 key의 원소보다 큰값을 찾기
			i++;
		}
		while (data[j] >= data[key] && j > start) {//<--오른쪽으로 출발하여 key의 원소보다 작은값을 찾기
			j--;
		}

		if (i > j) {//엇갈릴 경우!!!!!
			temp = data[i];
			data[j] = data[key];
			data[key] = temp;
		}
		else { // 엇갈리지 않았다면 i와 j를 교체 
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
		//재귀함수 호출  분할 정보
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}


int main(void) {
	quickSort(data, 0, number - 1);
	show();
	

	return 0;
}