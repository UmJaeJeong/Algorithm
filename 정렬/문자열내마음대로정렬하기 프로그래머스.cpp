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
	
	//미리 sort함수를 이용하여 n기준이 아닌 전체기준으로 정렬한다.
	sort(strings.begin(), strings.end());
	
	//정렬후 n기준으로 정렬하면 앞전에 정렬한것이 사전식이 포함되어
	//문제와같이 정렬된다.
	//이방법이외에 리턴값이 bool인 compare함수를 만들어 조건을 취하고 한번에
	//sort함수로 풀이하는 방법도 있다.
	//k=n; //전역변수에 값을 입력하여 compare함수를 만들떄 활용한다.
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