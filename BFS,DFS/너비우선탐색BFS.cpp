#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int number = 7;
int c[7];//checkȮ��
vector<int> a[8];//1~7���� �ε����� ã�� ���ؼ�  8���� vector�� ����

void bfs(int start) {
	queue<int> q;
	q.push(start);//��ó�� ť�� ������ ��ó�� ����� ������
	c[start] = true;//ù���� �湮ó��
	while (!q.empty()) {//ť�� �������� �ݺ�
		int x = q.front();
		q.pop();
		printf("%d", x);//�ʺ�켱���� ã���͵��� ��µ� ù���� ��带 ���� 
		for (int i= 0; i < a[x].size(); i++) {//���� ť���� ���� �׿��ҿ� ������ ��带 �湮
			int  y = a[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}

		}

	}
}

int main(void) {
	
	// 1�� 2�� ����
	a[1].push_back(2);
	a[2].push_back(1);
	// 1�� 3�� ����
	a[1].push_back(3);
	a[3].push_back(1);
	// 2�� 3�� ����
	a[2].push_back(3);
	a[3].push_back(2);
	// 2�� 4�� ����
	a[2].push_back(4);
	a[4].push_back(2);
	// 2�� 5�� ����
	a[2].push_back(5);
	a[5].push_back(2);
	// 3�� 6�� ����
	a[3].push_back(6);
	a[6].push_back(3);
	// 3�� 7�� ����
	a[3].push_back(7);
	a[7].push_back(3);
	// 4�� 5�� ����
	a[4].push_back(5);
	a[5].push_back(4);
	// 6�� 7�� ����
	a[6].push_back(7);
	a[7].push_back(6);
	// BFS�� ����
	bfs(1);
	return 0;

}