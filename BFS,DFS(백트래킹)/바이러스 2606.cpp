#include<iostream>
#include<vector>
using namespace std;
/*
바이러스가 걸린 컴퓨터는 네트워크상에 연결되어 있는 모든 웜 바이러스에 걸리게 된다.
*/

#define MAX 101

int c[MAX];
vector<int> a[MAX];
int cnt;

void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	for (int i = 0; i < MAX; i++) {
		if (c[i] == 0)continue;
		cnt++;
	}
	cout << cnt - 1;
	return 0;
}