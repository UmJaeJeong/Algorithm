#include<iostream>
using namespace std;
// 시간복잡도 ==>O(N*N)경우의 다익스트라 알고리즘


//다익스트라 최단경로를 구하는 공식 동적프로그래밍이나 그리드알고리즘에도 많이 사용된다.
//다이나믹프로그래밍 같은 경우는 한점에서 여러점으로 이동하는 경로의 최단거리를 모두 알기때문에 사용

//1.출발 노드를 설정
//2. 출발 노드를 기준으로 각 노드의 최소비용을 저장
//3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택
//4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려 최소비용 갱신
//5. 위 과정에서 3번~4번을 반복

int number = 6;
bool v[6];
int d[6];
int INF = 1000000000;

//전체그래프를  초기화
int a[6][6] = {
	{ 0, 2, 5, 1, INF, INF },
{ 2, 0, 3, 2, INF, INF },
{ 5, 3, 0, 3, 1, 5 },
{ 1, 2, 3, 0, 1, INF },
{ INF, INF, 1, 1, 0, 2 },
{ INF, INF, 5, INF, 2, 0 },
};
//시작점에서 인접한 노드와 최단의 거리를 가지고 있는 노드의 index찾기
int getSmallIndex() {
	int index = 0;
	int min = INF;
	for (int i = 0; i < number; i++) {
		//방문하지 않았는 노드 검색
		if (!v[i]) {
			//d[i]에 저장되어있는 최단거리를 가진 index 도출
			if (d[i] < min) {
				min = d[i];
				index = i;
			}
		}
	}
	return index;
}

void dijckstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];//start노드에서 각노드까지의 거리 저장
	}
	v[start] = true;
	//start노드와 end노드를 제외한 횟수 반복
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < number; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}


int main() {
	dijckstra(0);
	for (int i = 0; i < number; i++) cout << d[i];
	return 0;
}