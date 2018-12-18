#include<iostream>
#include<math.h>
using namespace std;
/*
분할 정복은 컴퓨터 과학에서 매우 중요한 알고리즘 중 하나
특정한 큰 문제가 있을 때 그것과 비슷한 모양의 작은 문제 여러 개로 큰 문제를 분할하여 해결한 뒤에 나중에
합쳐서 결과를 도출하는 알고리즘 
이러한 분할 정복과정에서 생기는 비효율적이ㅏㄴ 문제를 해결하기 위해 나타난 것이 ㅗㅇ적 프로그래밍 기법
하지만 아이러니하게도 동적 프로그래밍 문제보다 분할 정복 문제가 더 어려울 때가 많다

*/
/*
문제 : 
2차원 배열 
2의 n제곱 x 2의 n제곱
만약 2차원 배열의 크기가 위상황과 같다면 
왼쪽 위에 있는 칸이 하나가 아니라면 배열을 4등분함ㄴ후 크기가 같은 2의 n-1로 재귀적으로 순서 방문
재귀적으로 순서대로 방문 
*/

int cnt=0;
int N, C, R;
//row 행  column 열
void Visite(int n, int r, int c) {
	if (n == 2) {
		if (r == R && c == C) {
			cout << cnt;
			return;
		}
		cnt++;
		if (r== R&& c+1 == C) {
			cout << cnt;
			return;
		}
		cnt++;
		if (r+1 == R && c == C ) {
			cout << cnt;
			return;
		}
		cnt++;
		if(r+1 == R && c+1 == C){
			cout << cnt;
			return;
		}
		cnt++;
		return;
	}

	Visite(n / 2, r, c);
	Visite(n / 2, r, c + n / 2);
	Visite(n / 2, r + n / 2, c );
	Visite(n / 2, r + n / 2, c + n / 2);

}


int main() {
	cin >> N >> R>> C;
	Visite(pow(2,N),0,0);

	return 0;
}