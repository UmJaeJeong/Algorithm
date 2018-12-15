#include<iostream>
using namespace std;
#define MAX 1000001

/*
문제 :
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성 

입력 : 
첫째 줄에 자연수 M과 N이 빈칸을 사이에 두고 주어진다.(1<=M<=n<=1000000)

출력 :
한 줄에 하나씩, 증가하는 순서대로 소수를 출력
*/

int a[MAX];
int main() {
	a[1] = 1;
	for (int i = 2; i <MAX; i++) {
		for (int j = i*2; j < MAX; j+=i) {
			if (a[j] == 1) {
				continue;
			}
			else {
				a[j] = 1;
			}
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (a[i] == 0) cout <<i<< '\n';
	}
	return 0;
}