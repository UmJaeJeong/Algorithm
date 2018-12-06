#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//열혈강호 11375 문제
//n명의 직원
//m번호까지의 일
#define MAX 1001
vector<int> a[MAX];
int d[MAX];
bool c[MAX];

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;
		
		if (d[y] == 0 ||dfs(d[y])){
			d[y] = x;
			return true;
		}
	}
	return false;
}
int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j++) {
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
	cout << cnt << endl;

	return 0;
}