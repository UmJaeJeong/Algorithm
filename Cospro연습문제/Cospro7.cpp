#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*����7 Cospro
������������ ���ĵǾ��ִ� �� �迭 arrA, arrB�� �ϳ��� �迭�� ��ġ�� �մϴ�. ��, ��ģ ���� �迭�� ������������ ����
�Ǿ� �־�� �մϴ�.
���� ��� arrA = [-2, 3, 5, 9], arrB = [0, 1, 5]�� ��� �� �迭�� ������������ ���ĵ� �ϳ��� �迭�� ��ġ�� [-2, 0, 1, 3,
5, 5, 9]�� �˴ϴ�.
������������ ���ĵ� �� �迭 arrA�� arrB�� �־����� ��, �� �迭�� ������������ ���ĵ� �ϳ��� �迭�� ���ļ� return ��
���� solution �Լ��� �ۼ��Ϸ� �մϴ�. ��ĭ�� ä�� ��ü �ڵ带 �ϼ����ּ���.*/

vector<int> solution(vector<int> arrA, vector<int> arrB) {
	int arrA_idx = 0, arrB_idx = 0;
	int arrA_len = arrA.size();
	int arrB_len = arrB.size();
	vector<int> answer;

	while (arrA_idx < arrA_len && arrB_idx < arrB_len){
		if (arrA[arrA_idx] < arrB[arrB_idx]) {
			answer.push_back(arrA[arrA_idx++]);
		}
		else {
			answer.push_back(arrB[arrB_idx++]);
		}
	}

	while (arrA_idx < arrA_len)
		answer.push_back(arrA[arrA_idx++]);
	while (arrB_idx < arrB_len)
		answer.push_back(arrB[arrB_idx++]);
	return answer;
}

// �Ʒ��� �׽�Ʈ���̽� ����� �غ��� ���� main �Լ��Դϴ�.
int main() {
	vector<int> arrA = { -2, 3, 5, 9 };
	vector<int> arrB = { 0, 1, 5 };
	vector<int> ret = solution(arrA, arrB);

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "solution �Լ��� ��ȯ ���� {";
	for (int i = 0; i < ret.size(); i++) {
		if (i != 0) cout << ", ";
		cout << ret[i];
	}
	cout << "} �Դϴ�." << endl;
}