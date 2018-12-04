#include<vector>
#include<iostream>
using namespace std;
//KMP�˰��� ==> ��Ī�� �̿� 
//���λ�� ���̻縦 �̿��Ͽ� �ð����⵵�� ���̴� �˰���

//���� ���λ�� ���̻縦 ã��
vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;

	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		//�����Ѱ� üũ
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;

	for (int i = 0; i < parentSize; i++) {

	}
}


vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) table[i] = ++j;
	}
	return table;
}


int main() {
	string pattern = "abacaaba";
	vector<int> table = makeTable(pattern);
	for (int i = 0; i < table.size(); i++) {
		cout << table[i];
	}
	return 0;
}