#include<iostream>
using namespace std;
//�����佺�׳׽���ü �����ȿ� �����߿� �Ҽ��� �߷��� ����
int number = 10000;
int a[10001];

void Estotes() {
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number; j += i) {
			a[j] = 0;
		}
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] != 0)cout << a[i] << endl;
	}
}

int main() {
	Estotes();
	return 0;
}