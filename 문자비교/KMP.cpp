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
		if (pattern[i] == pattern[j]) table[i] = ++j;
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parnet.size();
	int patternSzie = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSzie - 1) {
				cout << i - patternSize + 2 << "��°���� ã�ҽ��ϴ�." << endl;
				j = table[j];
			}
			else {
				j++;
			}
		}

	}
}

int main() {
	string pattern = "abacaaba";
	string parent = "ababacabacaabacaaba";
	KMP(parent, pattern);
	return 0;
}