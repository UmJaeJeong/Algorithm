#include<iostream>
using namespace std;

/*
���� : 
���� �ѹ�  d(75) = 75+7+5 =87;
n,d(n),d(d(n)),d(d(d(n)))
�ּ� 5�ڸ� ����
100000
*/
#define MAX 10001
int a[MAX];
int b[MAX];

void d(int x) {
	int result = 0;
	int record = x;
	while (1) {
		result += record % 10;
		record /= 10;
		if (record == 0) break;
	}
	
	result = x + result;
	a[result] = 1;
}

int main() {
	
	for (int i = 1; i<=10000; i++) {
		d(i);
		if (a[i] == 1) continue;
		cout << i << '\n';
	}
	return 0;
}