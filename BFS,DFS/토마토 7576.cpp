/*
â�� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, ���� ���� ���� �丶�� ������ �ִ�.
���� �� �Ϸ簡 ������ ���� �丶����� ������ ���� �ִ� ���� �ʾ��� �丶����� ���� �丶���� ������ �޾� ����
�ϳ��� �丶���� ������ ����  ���� ������  �� �� �׹��⿡ �ִ� �丶���並 �ǹ�
�밢�� ���⿡ �̾������� ������ ���� ����
������ ���θ� ������
������ ������ �� ������ �ִ��� Ȯ��


�Է�  :
ù �ٿ��� ������ ũ�⸦ ��Ÿ���� M. N�� �־���
0�� ������ �丶��
-1�� �����
1�� ���� �丶��

*/

#include<iostream>
#include<queue>

using namespace std;
#define MAX 1001
int a[MAX][MAX];
int c[MAX][MAX];
int n, m;
int d1[4] = { 0,0,1,-1 };
int d2[4] = { 1,-1,0,0 };
int day;
int emptybox;
int Max = 0;

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}

void Print1() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	c[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> k = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = k.first + d1[i];
			int ny = k.second + d2[i];
			if (nx >= 0 && nx < n&&ny >= 0&&ny < m) {
				if ((a[nx][ny] == 0 || a[nx][ny] > a[k.first][k.second] + 1)) {
					a[nx][ny] = a[k.first][k.second] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}

	}
}

int main() {

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
		cout << endl;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1)bfs(i,j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (Max < a[i][j]) {
				Max = a[i][j];
			}


		}
	}

	//Print1();

	cout << Max-1 << endl;
	return 0;
}