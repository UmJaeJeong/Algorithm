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
	for(int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j+=i) {
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

	bool check = false;
	for (int k = 0; k < n.size(); k++) {
		check = false;
		for (int i = 2; i <= n[k]; i++) {

			for (int j = 2; j <= n[k]; j++) {
				cout << i << ' ' << j << endl;
				if (a[i] == 1 || a[j] == 1)continue;

				if (i+j == n[k]) {
					cout << n[k] << '=' << i << '+' << j << endl;
					check = true;
				}
				else if (i == n[k] && j == n[k]) {
					cout << "Goldbach's conjecture is wrong." << endl;
				}
			}

			if (check==true)break;

		}

	}

	return 0;
}