#include <iostream>

using namespace std;
//64비트 부호 없는 정수를 [0, 15] 범위의 정수 16개를 담는 배열로 사용하기
typedef unsigned long long uint64;//별칭 사용 


//mask의 index 위치에 쓰인 값을 반환
int get(uint64 mask, int index) {
	return (mask >> (index << 2)) & 15;
}

//mask의 index 위치를 value로 바꾼 결과를 반환
uint64 set(uint64 mask, int index, uint64 value) {
	return mask & ~(15LL << (index << 2)) | (value << (index << 2));
}

void main() {

}