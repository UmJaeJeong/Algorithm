#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*����8 Cospro
1������ N������ �ĺ��� ���ؼ� ��ǥ�� �����߽��ϴ�. ���� ��� ��ǥ ����� [1, 5, 4, 3, 2, 5, 2, 5, 5, 4]��� �������
[1��, 5��, 4��, 3��, 2��, 5��, 2��, 5��, 5��, 4��] �ĺ��� ��ǥ������ ��Ÿ���ϴ�. �̶�, ���� ���� ǥ�� ���� �ĺ��� ��ȣ
�� ���Ϸ��� �մϴ�.
�־��� solution �Լ��� �ĺ��� �� N�� ��ǥ�� ������ ����� ��� �迭 votes�� �Ű������� �־����� ��, ���� ���� ǥ��
���� �ĺ��� ��ȣ�� return �ϴ� �Լ��Դϴ�. �׷���, �ڵ� �Ϻκ��� �߸��Ǿ��ֱ� ������, ��� �Է¿� ���ؼ��� �ùٸ���
�������� �ʽ��ϴ�. �־��� �ڵ忡�� �� �ٸ� �����ؼ� ��� �Է¿� ���� �ùٸ��� �����ϵ��� �����ϼ���.
*/

vector<int> solution(int N, vector<int> votes) {
	int vote_counter[11] = { 0 }; //�ִ� �ĺ��ڰ� 10�� �迭0��°�� ������� ����
	for (int i = 0; i < votes.size(); i++) {//�ĺ����� ǥ�� ���
		vote_counter[votes[i]] += 1;
	}
	int max_val = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {//���� ���� ���� ��ǥ�� ���� �ĺ��ڿ� �� �ĺ����� �ο�
		if (max_val < vote_counter[i]) {
			max_val = vote_counter[i];
			cnt = 1;
		}
		else if (max_val == vote_counter[i]) {
			cnt += 1;
		}
	}

	vector<int> answer(cnt, 0);
	for (int i = 1, idx = 0; i <= N; i++) { //maxim�� ������ ���� ���� �� ����
		if (vote_counter[i] == max_val) {
			answer[idx] = i;
			idx += 1;
		}
	}
	return answer;
}


// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�. main�Լ��� �߸��� �κ��� ������, solution�Լ��� �����ϼ���.
int main() {
	int N1 = 5;
	vector<int> votes1 = { 1,5,4,3,2,5,2,5,5,4 };
	vector<int> ret1 = solution(N1, votes1);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "solution �Լ��� ��ȯ ���� {";
	for (int i = 0; i < ret1.size(); i++) {
		if (i != 0) cout << ", ";
		cout << ret1[i];
	}
	cout << "} �Դϴ�." << endl;

	int N2 = 4;
	vector<int> votes2 = { 1,3,2,3,2 };
	vector<int> ret2 = solution(N2, votes2);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "solution �Լ��� ��ȯ ���� {";
	for (int i = 0; i < ret2.size(); i++) {
		if (i != 0) cout << ", ";
		cout << ret2[i];
	}
	cout << "} �Դϴ�." << endl;
}