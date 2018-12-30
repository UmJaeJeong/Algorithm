#include<iostream>
#include<queue>
using namespace std;

/*
��� �ִ� �� : .
���� ���ִ� �� : *
���� �ִ� �� : X
����� �� : D == Destination
����ġ�� ��ġ : S == Start

�� �и��� ����ġ�� ���� �ִ� ĭ�� ������ �� ĭ�� �ϳ��� �̵� ����
(��, �Ʒ�, ����, ������)

���� �� �и��� ����ִ� ĭ���� Ȯ���Ѵ�.
���� �ִ� ĭ�� ������ �ִ� ����ִ� ĭ(��� ����)���� �� �и��� ����ִ� ĭ���� Ȯ�� 
���� ����ġ�� ���� ����� ������.
�� ����ġ�� ���� ���ִ� �������� �̵��� �� ����, ���� ����� �ұ��� �̵��� �� ����.
����ġ�� ���� �� ������ ĭ���� �̵��� �� ����.
*/
#define MAX 51
typedef pair<int, int> P;

int R, C;
char a[MAX][MAX];
int dc[4] = { 0,0,1,-1 };
int dr[4] = { 1,-1,0,0 };
int c[MAX][MAX];
int w[MAX][MAX];
int Sr, Sc, Dr, Dc;

void Print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << w[i][j] << ' ';
		}
		cout << endl;
	}
}


void bfs(int row, int col){
	queue<P> q;
	q.push(P(row, col));
	c[row][col] = 1;
	while (!q.empty()) {
		P k = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {	
			int nr = k.first + dr[i];
			int nc = k.second + dc[i];

			if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
				if (w[nr][nc] != 1 && a[nr][nc] != 'X'&& c[nr][nc]==0) {
					/*c[nr][nc] = c[k.first][k.second] + 1;
					q.push(P(nr, nc));*/
					if (w[nr][nc] > c[k.first][k.second] + 1||w[nr][nc]==0) {
						c[nr][nc] = c[k.first][k.second] + 1;
						q.push(P(nr, nc));
					}
					
				}

			}
		}

	}
	
}


void bfsWater(int row, int col)
{
	queue<P> q;
	q.push(P(row, col));
	w[row][col] = 1;
	while (!q.empty()) {
		P k = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = k.first + dr[i];
			int nc = k.second + dc[i];
			if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
				if (a[nr][nc] == '.' || w[nr][nc] > w[k.first][k.second] + 1) {
					w[nr][nc] = w[k.first][k.second] + 1;
					a[nr][nc] = '*';
					q.push(P(nr, nc));
				}
			}
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				Sr = i;
				Sc = j;
			}
			if (a[i][j] == 'D') {
				Dr = i;
				Dc = j;
			}

		}
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//�� ���� ������
			if (a[i][j] == '*' && w[i][j]==0)bfsWater(i, j);
			
		}
	}

	bfs(Sr, Sc);

	//cout << "�������̹�����" << endl;
	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		cout << w[i][j] << ' ';


	//	}
	//	cout << endl;
	//}

	//cout << "�δ��������̱�" << endl;
	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		cout << c[i][j] << ' ';
	//		

	//	}
	//	cout << endl;
	//}


	if (c[Dr][Dc] == 0) {
		cout << "KAKTUS";
	}
	else {
		cout << c[Dr][Dc] - 1;

	}

	return 0;
}