#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//미르코 우연히 길거리에서 양수 N 봄
//30이란 수를 존경
//N을 사용하여 30의 배수가 되는 가장 큰수 구하기
bool compare(char a, char b) {
	return a > b;
}

int main() {
	string n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n.size(); i++) {
		result += n[i] - 48;
	}

	if (n.find("0") == string::npos || result%3!=0) {
		cout << -1 << endl;
		return 0;
	}

	sort(n.begin(), n.end(),compare);
	cout << n << endl;

	return 0;
}
