#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//기본 매칭을 네트워크 플로어와 유사하다고 할 수 있음
//애드머드 카트 정점*간선의제곱
#define MAX 101

int n=3;//케이스
int m; //간선의 정보
vector<int> a[MAX];//각 정점과 간선정보
int d[MAX];//점유하고 있는 노드가 담김
bool c[MAX];//특정 노드를 처리를 했는지 확인;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		//방문했던 것이면 넘어감 
		if (c[y]) continue;
		c[y] = true;
		//아직 연결된 노드가 없거나 이미 연결되어 있는것
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}
int main(void) {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) cnt++;
	}

	cout << cnt << "개의 매칭이 이루어졌습니다." << endl;
	for (int i = 1; i <= 100; i++) {
		if (d[i] != 0) {
			cout << d[i] << "->" << i << endl;
		}
	}

}