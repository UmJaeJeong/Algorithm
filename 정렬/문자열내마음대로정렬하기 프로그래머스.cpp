#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;
int k;

bool compare(string a, string b) {
	return (a[k] == b[k]) ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
	//vector<string> answer;
	
	//�̸� sort�Լ��� �̿��Ͽ� n������ �ƴ� ��ü�������� �����Ѵ�.
	sort(strings.begin(), strings.end());
	
	//������ n�������� �����ϸ� ������ �����Ѱ��� �������� ���ԵǾ�
	//�����Ͱ��� ���ĵȴ�.
	//�̹���̿ܿ� ���ϰ��� bool�� compare�Լ��� ����� ������ ���ϰ� �ѹ���
	//sort�Լ��� Ǯ���ϴ� ����� �ִ�.
	//k=n; //���������� ���� �Է��Ͽ� compare�Լ��� ���鋚 Ȱ���Ѵ�.
	//sort(strings.begin(), strings.end(),compare);
	for (int i = 0; i < strings.size(); i++) {
		for (int j = 0; j<strings.size() - 1; j++) {
			if (strings[j][n]>strings[j + 1][n]) {
				string temp = strings[j];
				strings[j] = strings[j + 1];
				strings[j + 1] = temp;
			}

		}
	}
	
	return strings;
}

int main() {
	int n = 1;
	vector<string> strings;
	strings.push_back("sun");
	strings.push_back("bed");
	strings.push_back("car");
	vector<string> answer = solution(strings, n);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	cout << endl;
	strings.clear();
	n = 2;
	strings.push_back("abce");
	strings.push_back("abcd");
	strings.push_back("cdx");
	answer = solution(strings, n);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	cout << endl;

	return 0;
}