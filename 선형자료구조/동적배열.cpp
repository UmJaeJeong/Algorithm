#include<stdio.h>

void main() {
	int size=0; //배열의 크기
	int* Array=0; //실제 배열을 가르키는 포인터 (int 대신에 ElementType들로 바꿀수 있음);
	int capacity = 1;
	int M = 3;

	//배열 용량이 꽉 찼으면 재할당 받는다.
	if (size == capacity) {
		int newCapacity = capacity + M;
		int* newArray = new int[newCapacity];
		//기존의 자료를 복사한다.
		for (int i = 0; i < size; i++) {
			newArray[i] = Array[i];
			//기존의 배열을 삭제하고, 새배열로 바꿔치기
			if (Array) delete[] Array;
			Array = newArray;
			capacity = newCapacity;
		}
		//배열의 끝에 원소를 삽입한다.
		//Array[size++] = newValue
	}

	//결과적인 재할당 시간 O(N + M)
	//C++이나 C#인경우에는 vector나 ArrayList등을 사용하여 동적배열과 유사하게 사용한다.
}