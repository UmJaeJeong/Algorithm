#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*����9 Cospro
�� �л� A�� B�� ��� ������ �Ͽ����ϴ�. ��� ������ ��Ģ�� �Ʒ��� �����ϴ�.
1. ��� ���� �Ʒ����� ������ �����մϴ�. (0��° ĭ)
2. ������������ �մϴ�.
3. �̱�� ��� �� ĭ�� �ö󰡰�, ���� �� ĭ�� ��������, ���� ���ڸ��� �ֽ��ϴ�.
4. ��� ���� �Ʒ����� ���� ���ڸ��� �ֽ��ϴ�.
5. 2~4 ������ �� �� �ݺ��մϴ�.

A�� B�� ��� ������ �Ϸ��� �Ŀ�, A�� ��� �� �� ��° ĭ�� �ִ��� �ľ��Ϸ��� �մϴ�.
A�� B�� �� ���������� ����� ������� ����ִ� �迭 recordA�� recordB�� �Ű������� �־��� ��, ������ ��ģ ���� A
�� ��ġ�� return �ϵ��� solution �Լ��� �ۼ��߽��ϴ�. �׷���, �ڵ� �Ϻκ��� �߸��Ǿ��ֱ� ������, ��� �Է¿� ���ؼ�
�� �ùٸ��� �������� �ʽ��ϴ�. �־��� �ڵ忡�� �� �ٸ� �����ؼ� ��� �Է¿� ���� �ùٸ��� �����ϵ��� �����ϼ���.
*/

int func(int record) {//����� �� �̱�� ����� ���� ��
	if (record == 0) return 1;
	else if (record == 1) return 2;
	return 0;
}

int solution(vector<int> recordA, vector<int> recordB) {
	int cnt = 0;
	for (int i = 0; i < (int)recordA.size(); i++) {
		if (recordA[i] == recordB[i])  //����� ���
			continue;
		else if (recordA[i] == func(recordB[i]))  //�̰��� ���
			cnt = cnt + 3;
		else 
			cnt = max(0,cnt - 1); //���� ��� ���� cnt == 0�� ��� �������� ���Ѵٴ°��� ����
	}
	return cnt;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�. main�Լ��� �߸��� �κ��� ������, solution�Լ��� �����ϼ���.
int main() {
	vector<int> recordA = { 2,0,0,0,0,0,1,1,0,0 };
	vector<int> recordB = { 0,0,0,0,2,2,0,2,2,2 };
	int ret = solution(recordA, recordB);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "solution �Լ��� ��ȯ ���� " << ret << " �Դϴ�." << endl;
}