/*
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토 있을수 있다.
보관 후 하루가 지나면 익은 토마토들의 인접한 곳에 있는 익지 않않은 토마토들은 익은 토마토의 영향을 받아 익음
하나의 토마토의 인접한 곳은  왼쪽 오른쪽  앞 뒤 네방향에 있는 토마ㅣ토를 의미
대각선 방향에 이쓴ㄴ것은 영향을 주지 못함
가만히 놔두면 안익음
몇일이 지나야 다 익을수 있는지 확인


입력  :
첫 줄에는 상자의 크기를 나타내느 M. N이 주어짐
0은 안익은 토마토
-1은 빈상자
1은 익은 토마토

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