#include<iostream>
#include<vector>
using namespace std;
//1명이 할수있는일은 2가지씩
#define MAX 1001


int d[MAX];
vector<int> a[MAX];
bool c[MAX];
int n,m;
bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;
		
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}

	int cnt = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if (dfs(i)) cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}