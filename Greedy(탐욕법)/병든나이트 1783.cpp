#include<iostream>
#include<algorithm>
using namespace std; 

/*
병든 나이트가 N*M크기 체스판의 가장 왼쪽아래 칸에 위치해 있다. 병든 나이트는 건강한 보통 체[스의
나트와 다르게 4가지로만 움직일 수 있다.

//현위치 왼쪽 가장아래
//4가지 방법으로만 이동 가능
//이동횟수 4번이상 위의 이동방법을 한번씩 사용해야함
*/
int main() {
	int n, m;
	cin >> n>> m;
	int result = 1;

	if (n == 1)result = 1;
	else if (n == 2) {
		result = min(4, (m+1) / 2); //높이가 2이면 최대 3번 움직일수 있다.
	}
	else {// 높이가 3이상인 경우
		if (m >= 7)result = m - 2;
		else result = min(4, m);
	}
	cout << result << endl;
	return 0;
}