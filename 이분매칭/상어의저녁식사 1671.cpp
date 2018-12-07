#include<iostream>
#include<vector>
using namespace std;
//최대2마리 

#define MAX 51
vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n;
int s[MAX], v[MAX], k[MAX];//지능, 속도, 크기를 비교

bool dfs(int x) {
	for (int i= 0; i < a[x].size(); i++) {
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
			cin >> s[i] >> v[i] >> k[i];
	}

	//조건을 비롯한 간선 연결
	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			if (s[i] == s[j] && v[i] == v[j] && k[i] == k[j]) {
				a[i].push_back(j);
			}else
			if (s[i] >= s[j] && v[i] >= v[j] && k[i] >= k[j]) {
				a[i].push_back(j);

			}
			else if (s[i] <= s[j] && v[i] <= v[j] && k[i] <= k[j]) {
				a[j].push_back(i);

			}
		}
	}

	//최대 2마리를 먹을 수있음 
	int cnt = 0;
	for (int k = 1; k <= 2; k++) {
		for (int i = 1; i <= n; i++) {
			fill(c, c + MAX, false);
			if (dfs(i)) cnt++;
		}
	}

	cout << n-cnt << endl;
	return 0;
}