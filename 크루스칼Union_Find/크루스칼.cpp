#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�θ�ã��
int getParent(int Parent[], int a) {
	if (Parent[a] == a) return a;
	return Parent[a] = getParent(Parent, Parent[a]);
}

//�� �׷��� ��ġ�� ������
int UnionParent(int Parent[], int a, int b) {
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	if (a > b) return Parent[a] = b;
	return Parent[b] = a;
}

//�α׷���? ������ �������� ���Ͽ� �ִ��� Ȯ��
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