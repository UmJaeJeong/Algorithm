#include<iostream>
using namespace std;
// 500 100 50 10 5 1
int exchage(int x) {
	int answer = 1000-x;
	int cnt = 0;
	while (answer !=0) {
		int a = 0;
		if (answer / 500 > 0) {
			a = answer / 500;
			answer = answer % 500;
			cnt += a;
		}
		else if (answer / 100 > 0) {
			a = answer / 100;
			answer = answer % 100;
			cnt += a;
		}
		else if (answer / 50 > 0) {
			a = answer / 50;
			answer = answer % 50;
			cnt += a;
		}
		else if (answer / 10 > 0) {
			a = answer / 10;
			answer = answer % 10;
			cnt += a;
		}
		else if (answer / 5 > 0) {
			a = answer / 5;
			answer = answer % 5;
			cnt += a;
		}
		else{
			cnt += answer;
			answer = 0;
		}
	}
	

	return cnt;
}

//2번째 방법
int exchage2(int x) {
	int ret = 0;
	int n = 1000 - x;
	ret += n/ 500;
	n %=500;
	ret += n / 100;
	n %=100;
	ret += n / 50;
	n %= 50;
	ret += n / 10;
	n %= 10;
	ret += n / 5;
	n %= 5;
	ret += n;

	return ret;
}

int main() {
	int n;
	cin >> n;
	
	cout << exchage(n) << endl;
	cout << exchage(n) << endl;
}