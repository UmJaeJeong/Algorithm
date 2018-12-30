#include<iostream>
#include<queue>
using namespace std;

/*
비어 있는 곳 : .
물이 차있는 곳 : *
돌이 있는 곳 : X
비버의 굴 : D == Destination
고슴도치의 위치 : S == Start

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸중 하나로 이동 가능
(위, 아래, 왼쪽, 오른쪽)

물도 매 분마다 비어있는 칸으로 확장한다.
물이 있는 칸과 인접해 있는 비어있는 칸(적어도 한쪽)물도 매 분마다 비어있는 칸으로 확장 
물과 고슴도치는 돌을 통과할 수없다.
또 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.
고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다.
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
			//물 영역 넓히기
			if (a[i][j] == '*' && w[i][j]==0)bfsWater(i, j);
			
		}
	}

	bfs(Sr, Sc);

	//cout << "물웅덩이번지기" << endl;
	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		cout << w[i][j] << ' ';


	//	}
	//	cout << endl;
	//}

	//cout << "두더지움직이기" << endl;
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