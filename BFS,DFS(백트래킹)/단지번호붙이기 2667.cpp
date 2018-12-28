#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 26


string a[MAX];
int cnt[MAX*MAX];
int k;
int x[4] = { 0,0,-1,1 };
int y[4] = { 1,-1,0,0 };
int n;
int v[MAX][MAX];

void dfs(int i, int j) {
	v[i][j] = true;
	a[i][j] = '0';
	cnt[k]++;
	for (int s = 0; s < 4; s++) {
		int z = i + x[s];
		int c = j + y[s];
		if (z>=0&&z<n&& c>=0 && c<n && v[z][c]==0)
			if(a[z][c] == '1')dfs(z, c);
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <n; j++) {
			if (a[i][j] == '1'&&v[i][j] == 0) {
				dfs(i, j);
				k++;
			}
		}
	}
	sort(cnt, cnt + k);
	cout <<k<< "\n";

	for (int i = 0; i < k; i++) {
		cout << cnt[i] << "\n";
	}

	return 0;
}