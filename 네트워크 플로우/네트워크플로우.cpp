#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 100
#define INF 1000000000

//��Ʈ��ũ �÷ο� ==> Ư���� �������� �ٸ��������� �����Ͱ� �󸶳� ���� �귯���°� �����ϴ� �˰���

/*
Ư¡ : ���� ü��, ��Ʈ��ũ ������ ���� ���� �پ��� �о߿� Ȱ��
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
				//�湮���� ���� ��� �߿� �뷮�� ���� ���
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;//��θ� ���
					if (y == end) break;
				}
			}
		}

		if (d[end] == -1) break;
		int flow = INF;
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);

		}

		//�ּ� ������ŭ �߰�
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;

		}
		result += flow;
	}
}
