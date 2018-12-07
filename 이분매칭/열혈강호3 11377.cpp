#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 1001
int n,m,k;
vector<int> a[MAX];
int d[MAX];
bool c[MAX];
//n명 중에 k명은 최대 2개의 일을 할 수 있다.
bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y])continue;
		c[y] = true;

		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int w;
			cin >> w;
			a[i].push_back(w);
		}
	}

	int cnt=0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) cnt++;
	}

	int duo = 0;
	for (int i = 1; i <= n && duo < k; i++) {
		fill(c, c + MAX, false);
		if (dfs(i))  duo++;
	}

	cout << cnt + duo << endl;

	return 0;
}