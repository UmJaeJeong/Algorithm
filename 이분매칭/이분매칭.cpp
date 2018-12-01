#include <iostream>
#include<vector>
using namespace std;
#define MAX 101

//이분매칭==> 두가지의 집단을 가장 효과적으로 매칭시켜줄수 있는 알고리즘
/*
특징 : 최대매칭 의미
가장 많이 연결된 그래프
*/

vector<int> a[MAX];//초기에 매칭되는 값들
int d[MAX];//index와 매칭된 값
bool c[MAX];//처리한노드인지 유뮤 판단
int n = 3;

//매칭 성공한 경우 true, 실패한 경우 false
bool dfs(int x) {
	//연겨ㅔㄹ된 모든 노드에 대해서 들어갈 수있는지 시도
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		//이미처리한 노드는 스킵
		if (c[t]) continue;
		c[t] = true;

		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;


}
int main() {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);

	int count = 0;
	//최대한 넣기
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
	cout << count << "개의 매칭이 이루어졌습니다." << endl;
	for (int i = 1; i <= 100; i++) {
		if (d[i] != 0) {
			cout << d[i] << "->" << i << endl;
		}
	}
	return 0;
}