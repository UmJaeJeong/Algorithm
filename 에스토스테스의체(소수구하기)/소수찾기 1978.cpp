#include<iostream>
#include<math.h>
using namespace std;
/*
문제 :
주어진 수 N개 중에서 소수가 몇개인지 찾아서 출력하는 프로그램 작성

입력 :
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다.
다음으로 N개의 수가 주어지는데 수는 1000이하의 자연수이다.

출력 :
주어진 수들 중 소수의 개수를 출력한다.
*/

#define MAX 101
bool isPrime(int x) {
	if (x == 1) return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) return false;
	}
	return true;
}

int main() {
	int n;
	int a[MAX];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i]))sum++;
	}
	cout << sum << endl;
	return 0;
}