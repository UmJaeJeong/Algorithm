#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int number = 7;
int c[7];//check확인
vector<int> a[8];//1~7까지 인덱스를 찾기 위해서  8개의 vector를 만듬

void bfs(int start) {
	queue<int> q;
	q.push(start);//맨처음 큐의 시작점 맨처음 노드의 시작점
	c[start] = true;//첫번쨰 방문처리
	while (!q.empty()) {//큐가 빌때까지 반복
		int x = q.front();
		q.pop();
		printf("%d", x);//너비우선으로 찾은것들이 출력됨 첫번쨰 노드를 기준 
		for (int i= 0; i < a[x].size(); i++) {//현재 큐에서 꺼낸 그원소와 인접한 노드를 방문
			int  y = a[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}

		}

	}
}

int main(void) {
	
	// 1과 2을 연결
	a[1].push_back(2);
	a[2].push_back(1);
	// 1과 3를 연결
	a[1].push_back(3);
	a[3].push_back(1);
	// 2과 3를 연결
	a[2].push_back(3);
	a[3].push_back(2);
	// 2과 4을 연결
	a[2].push_back(4);
	a[4].push_back(2);
	// 2과 5를 연결
	a[2].push_back(5);
	a[5].push_back(2);
	// 3와 6를 연결
	a[3].push_back(6);
	a[6].push_back(3);
	// 3와 7을 연결
	a[3].push_back(7);
	a[7].push_back(3);
	// 4와 5를 연결
	a[4].push_back(5);
	a[5].push_back(4);
	// 6과 7을 연결
	a[6].push_back(7);
	a[7].push_back(6);
	// BFS를 수행
	bfs(1);
	return 0;

}