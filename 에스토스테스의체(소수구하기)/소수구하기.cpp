#include<iostream>
#include<math.h>
using namespace std;


//내가 생각한 소수확인 함수
bool isPrimeNumber(int x) {
	for (int i = 2; i <= x; i++) {
		if (x%i == 0)return false;
	}
	return true;
}

//제곱근을 이용하여 시간복잡도가 1/2로 줄이는 방법
//대칭으로 인해 반으로 줄일수 있다.
bool isPrimeNumber1(int x) {
	int end = sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x%i == 0) return false;
	}
	return true;
}
