#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
���� : 
N�ڸ� ���ڰ� �־����� ��, ���⼭ ���� K���� ������ ���� �� �ִ� ���� ū ���� ���ϴ� ���α׷�

�Է� : 
ù° �ٿ� N�� K�� �־����� (1<=K<N<500000)
��° �ٿ� N�ڸ� ���ڰ� �־�����. �� ���� 0���� �������� �ʴ´�.

��� : 
�Է����� �־��� ���ڿ��� K���� ������ �� ���� �� �ִ� ���� ū ���� ���
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