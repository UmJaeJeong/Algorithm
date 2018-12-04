#include<vector>
#include<iostream>
using namespace std;
//KMP알고리즘 ==> 대칭을 이용 
//접두사와 접미사를 이용하여 시간복잡도를 줄이는 알고리즘

//같은 접두사와 접미사를 찾음
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
				cout << i - patternSize + 2 << "번째에서 찾았습니다." << endl;
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