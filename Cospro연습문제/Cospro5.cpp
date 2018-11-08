// ������ ���� include�� ����� �� �ֽ��ϴ�.
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*����5�� Cospro5
������ ���� n x n ũ���� ���ڿ� 1���� n x n������ ���� �ϳ��� �ֽ��ϴ�.�̶� ���� ������ ���� ������ ��ġ�Ǿ��ִٸ� �̰��� n-�ҿ뵹�� ����� �θ��ϴ�.�ҿ뵹�� ������ 1�� 1������ n �� n ������ �밢���� �����ϴ� ������ ���� ���ؾ� �մϴ�.���� ������ �밢���� �����ϴ� ���� ���� 15�Դϴ�. ������ ũ�� n�� �־��� �� n-�ҿ뵹�� ���� �밢���� �����ϴ�
������ ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.
*/
int solution(int n) {
	// ���⿡ �ڵ带 �ۼ����ּ���.
	int answer = 0;
	int an[100][100] = {};
	int turn = 1;
	int value = 1;
	int max = n;
	int x = 0;
	int y = -1;

	while (n >= 0) {
		//��
		for (int i = 0; i < n; i++) {
			y = y + turn;
			an[x][y] = value;
			value++;
		}
		n--;

		for (int j = 0; j < n; j++) {
			x = x + turn;
			an[x][y] = value;
			value++;
		}
		turn *= -1;
	}

	for (int i = 0; i < max; i++) {
		answer += an[i][i];
	}
	
	return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
	int n1 = 3;
	int ret1 = solution(n1);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "solution �Լ��� ��ȯ ���� " << ret1 << " �Դϴ�." << endl;

	int n2 = 2;
	int ret2 = solution(n2);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "solution �Լ��� ��ȯ ���� " << ret2 << " �Դϴ�." << endl;
}