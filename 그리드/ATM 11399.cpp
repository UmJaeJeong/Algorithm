#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define max 1001
int n, m;
int a[max];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	int ret = 0;  

	for (int i = 0; i < n; i++) {
		ret = a[i]*(n-i);
	}
	cout << ret << endl;
	return 0;
}