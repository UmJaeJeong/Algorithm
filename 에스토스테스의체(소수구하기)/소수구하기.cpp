#include<iostream>
#include<math.h>
using namespace std;


//���� ������ �Ҽ�Ȯ�� �Լ�
bool isPrimeNumber(int x) {
	for (int i = 2; i <= x; i++) {
		if (x%i == 0)return false;
	}
	return true;
}

//�������� �̿��Ͽ� �ð����⵵�� 1/2�� ���̴� ���
//��Ī���� ���� ������ ���ϼ� �ִ�.
bool isPrimeNumber1(int x) {
	int end = sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x%i == 0) return false;
	}
	return true;
}
