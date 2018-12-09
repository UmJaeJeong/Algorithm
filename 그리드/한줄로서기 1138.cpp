#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 10
typedef pair<int, int> P;
int n;
int a[MAX];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int count = 0; 
		for (int j = 0; j < n; j++) {
			if (a[j] == 0) {
				if (count == x) {
					a[j] = i;
					break;
				}
				++count;
			}	
		}
		
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}