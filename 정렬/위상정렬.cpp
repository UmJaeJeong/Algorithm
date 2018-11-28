#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//�������� �˰���
//�ð����⵵ ==> O(N*N)
/*
Ư¡ : 1) �׷����� ��ȯ�� �Ǹ� ����� �� ����.  DAG(Directe Acyclic Graph)
	   2) ������ �������ִ� �۾�

	   ==>���������� ����Ŭ�� �ִ� �׷������� ����Ҽ� ���� ����
		  �������� ã���� ���⿡ ����� �� ����.
*/
#define MAX 10
int number, inDegree[MAX];
vector<int> a[MAX];

void Topologysort() {
	int result[MAX];
	queue<int> q;
	for (int i = 1; i <= number; i++) {
		//�������� 0�� ��� ť�� ����
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= number; i++) {
		if (q.empty()) return;//����Ŭ �߻� ���� �������� �Ҽ� ����
		//���Ե� ��� 
		int x =q.front();
		q.pop();//�������� 0 �� ��带 ����
		//���� �湮�� ��� �Է�
		result[i] = x;
		//���� �� ���� �ݺ�
		for (int i = 0;i<a[x].size(); i++) {//�̺κ� �򰥸�
			int y = a[x][i];
			//������ �ڸ��� ť�� ����
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	//���
	for (int i = 1; i <= number; i++) {
		cout << result[i] << ' ';
	}

}
int main() {
	number = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;
	Topologysort();
	return 0;
}