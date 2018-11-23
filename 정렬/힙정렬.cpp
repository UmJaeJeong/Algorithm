#include<stdio.h>
int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };
int main(void) {
	//힙을 구성
	//첫번 쨰 전체 트리 구조를 최대 힙 구조로 바꾼다.  구조로!!! 바꾼다 정렬이 되지 않았다
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	//힙구조가 되었는지 확인 출력
	/*for (int i = 0; i < number; i++) {
		printf("%d  ", heap[i]);
	}*/


	//크기를 줄여가며 반복적으로 힙을 구성  
	//제일 큰값을 맨뒤로 보내고 힙구조를 만들고 제일큰값을 뒤로 보내고 
	//힙구조를 만들고 재귀적으로 반복
	for (int i = number - 1; i >= 0; i--) { 
		int temp = heap[0];				//맨앞에 가장 큰 수를 맨뒤로 옮김 즉, 한개씩 정렬함
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			// 자식 중에 더 큰 값을 찾기	 2개의 자식중에 더큰 자식을 찾기
			if(c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
			// 루트보다 자식이 크다면 교환    다시 초기힙으로 바꿈
			if(c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	} 

	//결과 출력
	for (int i = 0; i < number; i++) {
		printf("%d  ", heap[i]);
	}
	return 0;
}