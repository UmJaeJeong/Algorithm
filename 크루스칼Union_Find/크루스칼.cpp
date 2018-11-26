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

	Node(int node[], int value) {
		this->node[0] = node[0];
		this->node[1] = node[1];
		this->value = value;
	}

	bool operator <(Node &node) {
		return this->value < node.value;
	}
};

int main() {

	return 0;
}