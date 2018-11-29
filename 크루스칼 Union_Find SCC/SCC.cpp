#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX 10001

//강한 결합 요소 : 강하게 결합된 정점 집합(SCC알고리즘)
/*
특징 : SCC는 같은 SCC에 속하는 두 정점은 서로 도달이 가능하다.
	   사이크링 발생하는 경우는 무조건 SCC에 해당된다.
	   무방향 그래프라면 그 그래프 전체는 무조건 SCC이다.
	   코사라주 알고리즘과 타잔알고리즘이 있다.

타잔 알고리즘 : 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘
*/

int d[MAX];//부모노드 입력받음
int id;
bool finished[MAX];//방문 했는지 확인
vector<int> a[MAX];
vector<vector<int>> SCC;//강결합되어 있는지 확인
stack<int> s;

//DFS는 총 정점의 갯수만큼만 실행
int dfs(int start) {
	d[start] = ++id;//노드마다 고유한 번호를 할당
	s.push(start);//스택에 자기자신 삽입

	int parent = d[start];
	for (int i = 0; i < a[start].size(); i++) {//Union-Find를 사용 각 부모를 입력 
		int y = a[start][i];//연결되어 있는 노드
		if (d[y] == 0) parent = min(parent, dfs(y));//방문하지 않은 이웃
		else if (!finished[y]) parent = min(parent, d[y]);//처리중
	}

	if (parent == d[start]) {//부모노드가 자기자신일 경우
		vector<int> scc;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == start) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(void) {
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}
	printf("SCC의 갯수: %d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		printf("%d번째 SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}