#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100001

int n;
int a[MAX];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}

	sort(a, a +n);
	int k = n*a[0];
	for (int i = 1; i < n; i++) {
		k = max(k, (n - i)*a[i]);
	}

	cout << k;

	return 0;
}