#include<iostream>
#define MAX 15
using namespace std;
//기본적으로 퀸의 이동은 좌우 위아래 모든방향을 직선형으로 움직일수 있다.
//대각선 방향으로도 끝까지 움직일 수 있다.
//제한 조건은 각행과 각열에 1개의 퀸밖에 올수 없다는 점이다.


int col[MAX];//index = row행  value = col열을 의미 
int n;
int cnt;

bool isPromise(int c) {
	for (int i = 1; i < c; i++) {
		if (col[i] == col[c]) {//위의 행들에 놓여있는 퀸와 같은 열에 놓여있는가?
			return false;
		}

		if (abs(col[i] - col[c]) == abs(i - c)) {// 위의 퀸들과 대각선에 놓여있는가?
			return false;
		}
	}

	return true;
}


void dfs(int row) {
	if (row > n) {
		cnt++;
	}//끝까지 탐색하여 방법이 1개씩 증가 
	else {
		for (int i = 1; i <= n; i++) {
			col[row] = i;
			//유망한 노드 탐색
			if (isPromise(row)) {
				dfs(row + 1);
			}
			else {//유망하지 않은 노드 //가지치기 !!
				col[row] = 0;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		col[1] = i;
		dfs(2);
	}

	cout << cnt << endl;
	return 0;

}