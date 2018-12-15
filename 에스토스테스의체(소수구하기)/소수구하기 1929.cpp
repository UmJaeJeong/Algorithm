#include<iostream>
using namespace std;
#define MAX 1000001

/*
���� :
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ� 

�Է� : 
ù° �ٿ� �ڿ��� M�� N�� ��ĭ�� ���̿� �ΰ� �־�����.(1<=M<=n<=1000000)

��� :
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ���
*/

int a[MAX];
int main() {
	a[1] = 1;
	for (int i = 2; i <MAX; i++) {
		for (int j = i*2; j < MAX; j+=i) {
			if (a[j] == 1) {
				continue;
			}
			else {
				a[j] = 1;
			}
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (a[i] == 0) cout <<i<< '\n';
	}
	return 0;
}