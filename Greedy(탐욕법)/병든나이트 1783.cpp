#include<iostream>
#include<algorithm>
using namespace std; 

/*
���� ����Ʈ�� N*Mũ�� ü������ ���� ���ʾƷ� ĭ�� ��ġ�� �ִ�. ���� ����Ʈ�� �ǰ��� ���� ü[����
��Ʈ�� �ٸ��� 4�����θ� ������ �� �ִ�.

//����ġ ���� ����Ʒ�
//4���� ������θ� �̵� ����
//�̵�Ƚ�� 4���̻� ���� �̵������ �ѹ��� ����ؾ���
*/
int main() {
	int n, m;
	cin >> n>> m;
	int result = 1;

	if (n == 1)result = 1;
	else if (n == 2) {
		result = min(4, (m+1) / 2); //���̰� 2�̸� �ִ� 3�� �����ϼ� �ִ�.
	}
	else {// ���̰� 3�̻��� ���
		if (m >= 7)result = m - 2;
		else result = min(4, m);
	}
	cout << result << endl;
	return 0;
}