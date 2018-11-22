#include<iostream>
using namespace std;
//버블정렬
/*
버블정렬 : 옆에 있는 값과 비교하여 더작은 값을 앞으로 보내기(직관적 방법, 효율성이 가장 떨어짐)
시간 복잡도 : O(N*N)  <실제 수행시간은 섲ㄴ택정렬보다 느리며 정렬중에 가장 느리다.>
*/
void main() {
	int i, j, temp;
	int array[10] = { 10,1,5,4,9,6,3,7,2,8 };

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (array[j] > array[j + 1]) {//스와핑
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

}