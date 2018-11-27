#include<iostream>
using namespace std;
//동적계획법
/*BOJ문제 11726번
2xN 크기의 직사각형을 1x2, 2x1타일로 채우는 방법의 수를 구하는 프로그램을 작성
첫번째 줄에 N이 주어짐(1<=N<=1000)
첫째 줄에 2xN 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지 출력
*/

//점화식으로 문제를 푼다
//메모이제이션을 한다
//공감각적 능력
int dp[1001] = { 0, };//메모이제이션

int solution(int n) {
	//2x1일 경우 방법은 1가지방법 (2x1타일 하나)
	if (n == 0)return 1;
	//2x2일 경우 방법은 위의 2x1방법을 제외한 방법은 1가지방법(1x2타일 하나)
	if (n == 1) return 1;
	//값이 들어 있는 경우 그 값을 리턴
	if (dp[n] != 0) return dp[n]%10007;
	//2x3이상의 타일부터~ 
	return dp[n] = solution(n - 1) + solution(n - 2);
}

int main(void) {
	int N;
	cin >> N;
	printf("%d",solution(N));

	return 0;
}