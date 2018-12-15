#include<iostream>
#include<math.h>
using namespace std;
/*
���� :
�־��� �� N�� �߿��� �Ҽ��� ����� ã�Ƽ� ����ϴ� ���α׷� �ۼ�

�Է� :
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�.
�������� N���� ���� �־����µ� ���� 1000������ �ڿ����̴�.

��� :
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.
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