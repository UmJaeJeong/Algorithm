#include<iostream>
using namespace std;
//동전의 종류 n가지
//그 가치의 합 k
//동전 개수의 최솟값
#define max 1000001

int n, k;
int a[max];
int ret;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int x = n;
	for (int i = n - 1; i >= 0; i--) {
		ret += k / a[i];
		k %= a[i];
	}
	
	cout <<ret<< endl;
	return 0;
}