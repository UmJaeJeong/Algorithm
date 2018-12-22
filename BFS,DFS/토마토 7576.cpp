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

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	c[i][j];
	while (!q.empty()) {
		pair<int, int> k = q.front();
		q.pop();
		for (int x = 0; x < 4; x++) {
			int nx = k.first + d1[x];
			int ny = k.second + d2[x];
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n) {
				if (c[nx][ny] == 0 && a[nx][ny] != -1) {
					q.push(make_pair(nx,ny));
					c[nx][ny] = c[k.first][k.second] + 1;
					a[nx][ny] = 1;
					if (Max < c[nx][ny]) Max = c[nx][ny];
				}
			}
		}


	}
}

void init() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = 0;
		}
	}
	day = 0;
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1)emptybox++;
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			init();
			if (a[i][j] == 1)bfs(i, j);
		}
	}

	cout << Max;
	return 0;
}