#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�⺻ ��Ī�� ��Ʈ��ũ �÷ξ�� �����ϴٰ� �� �� ����
//�ֵ�ӵ� īƮ ����*����������
#define MAX 101

int n=3;//���̽�
int m; //������ ����
vector<int> a[MAX];//�� ������ ��������
int d[MAX];//�����ϰ� �ִ� ��尡 ���
bool c[MAX];//Ư�� ��带 ó���� �ߴ��� Ȯ��;

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		//�湮�ߴ� ���̸� �Ѿ 
		if (c[y]) continue;
		c[y] = true;
		//���� ����� ��尡 ���ų� �̹� ����Ǿ� �ִ°�
		if (d[y] == 0 || dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}
int main(void) {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) cnt++;
	}

	cout << cnt << "���� ��Ī�� �̷�������ϴ�." << endl;
	for (int i = 1; i <= 100; i++) {
		if (d[i] != 0) {
			cout << d[i] << "->" << i << endl;
		}
	}

}