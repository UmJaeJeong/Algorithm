#include<iostream>
#define MAX 15
using namespace std;
//�⺻������ ���� �̵��� �¿� ���Ʒ� �������� ���������� �����ϼ� �ִ�.
//�밢�� �������ε� ������ ������ �� �ִ�.
//���� ������ ����� ������ 1���� ���ۿ� �ü� ���ٴ� ���̴�.


int col[MAX];//index = row��  value = col���� �ǹ� 
int n;
int cnt;

bool isPromise(int c) {
	for (int i = 1; i < c; i++) {
		if (col[i] == col[c]) {//���� ��鿡 �����ִ� ���� ���� ���� �����ִ°�?
			return false;
		}

		if (abs(col[i] - col[c]) == abs(i - c)) {// ���� ����� �밢���� �����ִ°�?
			return false;
		}
	}

	return true;
}


void dfs(int row) {
	if (row > n) {
		cnt++;
	}//������ Ž���Ͽ� ����� 1���� ���� 
	else {
		for (int i = 1; i <= n; i++) {
			col[row] = i;
			//������ ��� Ž��
			if (isPromise(row)) {
				dfs(row + 1);
			}
			else {//�������� ���� ��� //����ġ�� !!
				col[row] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		col[1] = i;
		dfs(2);
	}

	cout << cnt << endl;
	return 0;

}