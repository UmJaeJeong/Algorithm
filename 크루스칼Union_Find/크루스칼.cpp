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

	//������ ������� �������� ���� class ���ο� �����ڸ� �����س���
	sort(N.begin(), N.end());

	//�� ������ ���Ե� �׷����� ������� ����
	int set[7];//n�� ����� �ƴ϶� ����� �ȵȴ�..?
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	//�Ÿ��� ���� 0���� �ʱ�ȭ
	int sum = 0; 
	for (int i = 0; i < N.size(); i++) {
		//������ �θ� ����Ű�� �ʴ� ���, �� ����Ŭ�� �߻����� ���� ��
		if (!FindParent(set, N[i].node[0] - 1, N[i].node[1] - 1)){//set�� �迭�� 0���� �����ϱ⶧���� node�� ���� 1�� ���ִ� ������ �θ� Ȯ���Ѵ�.
			sum += N[i].value;
			UnionParent(set, N[i].node[0] - 1, N[i].node[1] - 1);
		}

	}
	printf("%d", sum);


	return 0;
}