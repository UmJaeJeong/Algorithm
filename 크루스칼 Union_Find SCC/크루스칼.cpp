#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//부모찾기
int getParent(int Parent[], int a) {
	if (Parent[a] == a) return a;
	return Parent[a] = getParent(Parent, Parent[a]);
}

//두 그래프 합치기 합집합
int UnionParent(int Parent[], int a, int b) {
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	if (a > b) return Parent[a] = b;
	return Parent[b] = a;
}

//두그래프? 집합이 같은곳에 속하여 있는지 확인
int FindParent(int Parent[], int a, int b) {
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	if (a == b) return 1;
	return 0;
}

class Node {
public:
	int node[2];
	int value;

	Node(int a,int b, int value) {
		this->node[0] = a;
		this->node[1] = b;
		this->value = value;
	}

	bool operator <(Node &node) {
		return this->value < node.value;
	}
};

int main() {
	int n = 7;
	int m = 11;
	vector<Node> N;
	N.push_back(Node(1, 7, 12));
	N.push_back(Node(1, 4, 28));
	N.push_back(Node(1, 2, 67));
	N.push_back(Node(1, 5, 17));
	N.push_back(Node(2, 4, 24));
	N.push_back(Node(2, 5, 62));
	N.push_back(Node(3, 5, 20));
	N.push_back(Node(3, 6, 37));
	N.push_back(Node(4, 7, 13));
	N.push_back(Node(5, 6, 45));
	N.push_back(Node(5, 7, 73));

	//간선의 비용으로 오름차순 정렬 class 내부에 연산자를 정의해놓음
	sort(N.begin(), N.end());

	//각 정점이 포함된 그래프가 어디인지 저장
	int set[7];//n은 상수가 아니라 사용이 안된다..?
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	//거리의 합을 0으로 초기화
	int sum = 0; 
	for (int i = 0; i < N.size(); i++) {
		//동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때
		if (!FindParent(set, N[i].node[0] - 1, N[i].node[1] - 1)){//set은 배열이 0부터 시작하기때문에 node의 값에 1을 빼주는 것으로 부모를 확인한다.
			sum += N[i].value;
			UnionParent(set, N[i].node[0] - 1, N[i].node[1] - 1);
		}

	}
	printf("%d", sum);


	return 0;
}