#include <iostream>
#include<vector>
using namespace std;
#define MAX 101

//�̺и�Ī==> �ΰ����� ������ ���� ȿ�������� ��Ī�����ټ� �ִ� �˰���
/*
Ư¡ : �ִ��Ī �ǹ�
���� ���� ����� �׷���
*/

vector<int> a[MAX];//�ʱ⿡ ��Ī�Ǵ� ����
int d[MAX];//index�� ��Ī�� ��
bool c[MAX];//ó���ѳ������ ���� �Ǵ�
int n = 3;

//��Ī ������ ��� true, ������ ��� false
bool dfs(int x) {
	//���ܤĤ��� ��� ��忡 ���ؼ� �� ���ִ��� �õ�
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		//�̹�ó���� ���� ��ŵ
		if (c[t]) continue;
		c[t] = true;

		//����ְų� ���� ��忡 �� �� ������ �ִ� ���
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;


}
int main() {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);

	int count = 0;
	//�ִ��� �ֱ�
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
	cout << count << "���� ��Ī�� �̷�������ϴ�." << endl;
	for (int i = 1; i <= 100; i++) {
		if (d[i] != 0) {
			cout << d[i] << "->" << i << endl;
		}
	}
	return 0;
}