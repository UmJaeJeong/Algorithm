#include<iostream>
using namespace std;
//플로이드와샬 알고리즘 
//시간 복잡도 ==> O(N*N*N)
//다익스타 알고리즘 경우에는 start노드 즉, 한점에서 모든 노드의 최단경로를 알고리즘
//하지만, 플로이드와샬 알고리즘 경우에는 N:N 즉, 다 대 다의 모든 노드들간의 최단경로를 알려주는 알고리즘
//다익스트라와 플로이드와샬 둘다 다이나믹프로그래밍에 의거한다.
int INF = 1000000000;
int number = 4;

//입력된 모든노드들의 경로 
int a[4][4] = {
	{ 0, 5, INF, 8 },
{ 7, 0, 9, INF },
{ 2, INF, 0, 4 },
{ INF, INF, 3, 0 }
};

void floydwarshall() {
	int d[4][4];

	//init 초기화
	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			d[i][j] = a[i][j];

	//거쳐가는 노드 중심
	for(int k=0; k<number;k++)
		//시작점
		for(int i=0; i<number;i++)
			//끝점
			for (int j = 0; j < number; j++) 
				if (d[i][k] + d[k][j] < d[i][j]) 
					d[i][j] = d[i][k] + d[k][j];

	//출력
	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			cout << i+1 << '~' << j+1<<' '<< d[i][j] << endl;
				
}


int main() {
	floydwarshall();
	return 0;
}