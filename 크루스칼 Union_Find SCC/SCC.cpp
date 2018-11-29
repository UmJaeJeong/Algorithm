#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX 10001

//���� ���� ��� : ���ϰ� ���յ� ���� ����(SCC�˰���)
/*
Ư¡ : SCC�� ���� SCC�� ���ϴ� �� ������ ���� ������ �����ϴ�.
	   ����ũ�� �߻��ϴ� ���� ������ SCC�� �ش�ȴ�.
	   ������ �׷������ �� �׷��� ��ü�� ������ SCC�̴�.
	   �ڻ���� �˰���� Ÿ�ܾ˰����� �ִ�.

Ÿ�� �˰��� : ��� ������ ���� DFS�� �����Ͽ� SCC�� ã�� �˰���
*/

int d[MAX];//�θ��� �Է¹���
int id;
bool finished[MAX];//�湮 �ߴ��� Ȯ��
vector<int> a[MAX];
vector<vector<int>> SCC;//�����յǾ� �ִ��� Ȯ��
stack<int> s;

//DFS�� �� ������ ������ŭ�� ����
int dfs(int start) {
	d[start] = ++id;//��帶�� ������ ��ȣ�� �Ҵ�
	s.push(start);//���ÿ� �ڱ��ڽ� ����

	int parent = d[start];
	for (int i = 0; i < a[start].size(); i++) {//Union-Find�� ��� �� �θ� �Է� 
		int y = a[start][i];//����Ǿ� �ִ� ���
		if (d[y] == 0) parent = min(parent, dfs(y));//�湮���� ���� �̿�
		else if (!finished[y]) parent = min(parent, d[y]);//ó����
	}

	if (parent == d[start]) {//�θ��尡 �ڱ��ڽ��� ���
		vector<int> scc;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == start) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(void) {
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}
	printf("SCC�� ����: %d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		printf("%d��° SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("\n");
	}
	return 0;
}