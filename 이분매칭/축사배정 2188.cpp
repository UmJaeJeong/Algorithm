#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//최대한 축사에 많이 들어가게 하기
//n 소의 마릿수 
//M개의 축사
#define MAX 201
int n, m;
vector<int> a[MAX];
int d[MAX];
bool c[MAX];

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		c[y] = true;
		if (d[y] == 0 || dfs(y)) {
			d[y] = x;
			return true;
		}
	}
	return false;
	
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int d;
			cin >> d;
			a[i].push_back(d);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++){
		fill(c, c + MAX, false);
		if (dfs(i))cnt++;
	}
	cout << cnt;
	return 0; 
}