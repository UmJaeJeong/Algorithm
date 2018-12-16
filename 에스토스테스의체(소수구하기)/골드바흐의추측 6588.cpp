#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
//4보다 큰 모든 짝수는 두홀수 소수의 합으로 나타낼수있다.
//정수 6<=n<=1000000
#define MAX 1000001
int a[MAX];
int main() {
	a[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j += i) {
			if (a[j] == 1)continue;
			a[j] = 1;
		}
	}

	vector<int> n;
	for (int i = 0; i < 100000; i++) {
		int x;
		cin >> x;
		if (x == 0) break;
		n.push_back(x);
	}

	for (int k = 0; k < n.size(); k++) {
		for (int i = n[k]; i >= n[k] / 2; i--) {
			if (a[i] == 1 || a[n[k] - i] == 1) continue;
			if (i + (n[k] - i) == n[k]) {
				cout << n[k] << " = " << n[k] - i << " + " << i << endl;
				break;
			}
			else if (i == n[k] / 2) {
				cout << "Goldbach's conjecture is wrong." << endl;
			}
		}

	}

	return 0;
}