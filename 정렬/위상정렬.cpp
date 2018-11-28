#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//위상정렬 알고리즘
//시간복잡도 ==> O(N*N)
/*
특징 : 1) 그래프가 순환이 되면 사용할 수 없다.  DAG(Directe Acyclic Graph)
	   2) 순서가 정해져있는 작업

	   ==>위상정렬이 사이클이 있는 그래프에서 사용할수 없는 이유
		  시작점을 찾을수 없기에 사용할 수 없음.
*/
#define MAX 10
int number, inDegree[MAX];
vector<int> a[MAX];

void Topologysort() {
	int result[MAX];
	queue<int> q;
	for (int i = 1; i <= number; i++) {
		//진입차수 0인 노드 큐에 삽입
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= number; i++) {
		if (q.empty()) return;//사이클 발생 으로 위상정렬 할수 없음
		//삽입된 노드 
		int x =q.front();
		q.pop();//진입차수 0 인 노드를 방출
		//먼저 방문한 노드 입력
		result[i] = x;
		//간선 수 많은 반복
		for (int i = 0;i<a[x].size(); i++) {//이부분 헷갈림
			int y = a[x][i];
			//간선을 자르고 큐에 삽입
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	//출력
	for (int i = 1; i <= number; i++) {
		cout << result[i] << ' ';
	}

}
int main() {
	number = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	Topologysort();
	return 0;
}