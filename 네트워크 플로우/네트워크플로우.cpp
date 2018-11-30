#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100
#define INF 1000000000

//네트워크 플로우 ==> 특정한 지점에서 다른지점으로 데이터가 얼마나 많이 흘러가는가 측정하는 알고리즘

/*
특징 : 교통 체증, 네트워크 데이터 전송 등의 다양한 분야에 활용
*/

int n = 6;
int result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end) {
	while (true) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				//방문하지 않은 노드 중에 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;//경로를 기억
					if (y == end) break;
				}
			}
		}

		if (d[end] == -1) break;
		int flow = INF;
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);

		}

		//최소 유량만큼 추가
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;

		}
		result += flow;
	}
}
