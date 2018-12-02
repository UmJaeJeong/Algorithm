#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 32001
//�θ��� Ű�� ��
//�Ϻ� �л����� Ű�� ���Ͽ� �ټ����
//M�� Ű�� ���� Ƚ��

int n, inDegree[MAX], result[MAX];
vector<int> a[MAX];

void topolgysort() {
	queue<int> q;
	//���� ������ 0�� ��带 ť�� ����.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	//������ ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮�Ѵ�.
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			//���Ӱ� ���������� 0�� �� ������ ť�� ����
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i];
	}

}

int main() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		inDegree[y]++;
	}
	topolgysort();
	return 0;
}
