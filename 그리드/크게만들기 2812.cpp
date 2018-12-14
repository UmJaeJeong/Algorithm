#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
문제 : 
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가자 큰 수를 구하는 프로그램

입력 : 
첫째 줄에 N과 K가 주어진다 (1<=K<N<500000)
둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

출력 : 
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력
*/

int main() {
	int n, k;
	string a;

	cin >> n >> k>>a;

	vector<char> result;
	int i = 0; 
	while (i != a.size()) {
		while (k != 0 && !result.empty() && result.back() < a[i]) {
			result.pop_back();
			k--;
		}
		result.push_back(a[i]);
		i++;
	}
	while (k--) {
		result.pop_back();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	

	
	return 0;
}