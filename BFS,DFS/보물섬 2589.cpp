#include<iostream>
#include<string>
#include<queue>
#include <utility>
using namespace std;
#define MAX 51

char a[MAX][MAX];
int c[MAX][MAX];
int Max;
int d1[4] = { 0,0,1,-1 };
int d2[4] = { 1,-1,0,0 };
int n, m;


void bfs(int i, int j) {
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	c[i][j] = 1;
	while (!q.empty()) {
		pair<int, int> k = q.front();
		q.pop();
		for (int x = 0; x < 4; x++) {
			int nx = k.first + d1[x];
			int ny = k.second + d2[x];

			if (nx >= 0 && nx<n && ny >= 0 && ny<m) {
				if (a[nx][ny] == 'L' && c[nx][ny]==0) {
					q.push(make_pair(nx, ny));
					c[nx][ny] = c[k.first][k.second] + 1;
					if (c[nx][ny]>Max) Max = c[nx][ny];
				}
			}
		}
	}
	
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = 0;
		}
	}
}

int main() {
	cin >> n>> m;

	for (int i = 0; i < n; i++) {
			cin>>a[i];		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (a[i][j] == 'L') {
				init();
				bfs(i, j);
			}
			
		}
	}
	cout << Max-1;
	
	return 0;
}