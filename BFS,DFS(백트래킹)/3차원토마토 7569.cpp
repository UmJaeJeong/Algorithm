#include<iostream>
#include<queue>
using namespace std;
#define MAX 101

int a[MAX][MAX][MAX];
int N, M, H;
int d1[6] = { 0,0,0,0,1,-1 };
int d2[6] = { 0,0,1,-1,0,0 };
int d3[6] = { 1,-1,0,0,0,0 };

class box {
public:
	int height;
	int row;
	int col;
	box(int h, int r, int c) {
		height = h;
		row = r;
		col = c;
	}
};

void bfs(int h, int n, int m) {
	queue<box> q;
	q.push(box(h, n, m));

	while (!q.empty()) {
		box k = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nh = k.height + d1[i];
			int nn = k.row + d2[i];
			int nm = k.col + d3[i];

			if ((nh>=0 && nh<H &&nn>=0&&nn<N&&nm>=0&&nm<M)||a[nh][nn][nm]>a[k.height][k.row][k.col]+1 ) {
				a[nh][nn][nm] = a[k.height][k.row][k.col] + 1;
				bfs(nh, nn, nm);
				q.push(box(nh,nn,nm));
			}
		}
	}

}

int mian() {
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> a[k][i][j];
			}
		}
	}

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[k][i][j] == 1) bfs(k, i, j);
			}
		}
	}

	int answer = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[k][i][j] == 0) {
					answer = 0;
					break;
				}
				if (answer < a[k][i][j]) answer = a[k][i][j];
			}
		}
	}

	cout << answer << endl;
	return 0;
}