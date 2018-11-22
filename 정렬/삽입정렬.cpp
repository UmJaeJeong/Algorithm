#include<iostream>
using namespace std;
//선택정렬
/*
선택정렬 : 각 숫자를 적절한 위치에 삽입하는 방법(필요할때만 위치를 바꿈)
			<이미 정렬되어 있다고 가정>

시간 복잡도 : O(N*N)  >> 선택, 버블, 삽입의 시간 복잡도는 동일하지만 삽입정렬이 가장빠르다
				<거의 정렬된 상태라면 가장 효율적인 삽입정렬>
*/

void main() {
	int i, j, temp;
	int array[10] = { 10,1,5,4,9,6,3,7,2,8 };
	
	for (i = 0; i < 9; i++) {//i의 값을 받는 j를 사용할때 j+1과 같이 사용하기때문에 9미만으로 조건을 검
		j = i;
		while (array[j] > array[j+1]) {//정렬된 상태의 배열들이 들어오면 가장 효율적임
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
		
	}

	//for~ each문
	for (int k : array) cout << k << " ";
}