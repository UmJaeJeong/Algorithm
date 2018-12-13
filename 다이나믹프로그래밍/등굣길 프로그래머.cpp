#include <string>
#include <vector>
#include<iostream>
using namespace std;
#define MAX 101
#define MOD 1000000007
int a[MAX][MAX];


int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	a[1][1] = 1;
	for (int i = 0; i<puddles.size(); i++) {
		a[puddles[i][1]][puddles[i][0]] = -1;

	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == -1) {
				a[i][j] = 0; continue;
			}
			if (i>1 || j>1) {
				a[i][j] = (a[i - 1][j] + a[i][j - 1]) % MOD;
			}
		}
	}


	return answer = a[n][m];
}
