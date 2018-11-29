#include<stdio.h>

//부모 노드 찾기
int getParent(int Parent[], int x) {
	//자기자신이 부모노드일 경우
	if (Parent[x] == x) return x;
	//재귀함수를 이용하여 직관적으로 찾기
	return Parent[x] = getParent(Parent, Parent[x]);
}

//두 노드 or 두 그래프를 합집합 하기
int unionParent(int Parent[], int a, int b) {
	//각 부모노드의 번호를 찾음
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	//노드 번호가 작은것으로 합집합 하는것이 일반적
	if (a > b) return Parent[a] = b;
	return Parent[b] = a;
}

//두 노드가 연결되어 있는지 아닌지 판별  판별후 
//만약 연결되지 않은것이라면 합집합을 통해 연결 시켜줌
int findParent(int Parent[], int a, int b) {
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	//두 노드가 연결되어 있는경우 true
	if (a == b)return 1;
	//두노드가 연결되어 있찌 않은 경우 false
	return 0;
}


int main() {
	int parent[11];
	//하나도 연결되지 않고 독립적으로 존재하는 노드 
	//각 자기자신이 부모노드임
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));

	return 0;
}