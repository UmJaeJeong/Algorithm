#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
�ϳ��� ���� ������ �̿��Ͽ� ������ ���Ը� �����Ϸ��� �Ѵ�.�� ������ �� ���� ������ �����̳� �߸� �÷�����
���ð� �޷��ְ�, ������ ���̴� ����. �Ǥ���, ������ ���ʿ��� �����ߵ鸸 ������ �ְ� �ٸ��ʿ���
�����Ϸ��� ���Ǹ� �÷����� �� �ִ�.
���԰� ���� ������ N���� �����߰� �־�����, ���ߵ��� ����Ͽ� ������ �� ���� ���� ���� ������
�ּڰ��� ���ϴ� ���α׷� �ۼ�
*/
int main() {
	int n;
	cin >> n;
	vector<int> a;
	int result = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		if (result < a[i])break;
		result += a[i];
		
	}

	cout << result;
	return 0;
}