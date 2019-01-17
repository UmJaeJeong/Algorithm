#include<iostream>
using namespace std;
//동적계획법 -> 완전탐색으로 활용
//BFS활용
//-1로 설정하면 넣은 값들이 모두9개 이상일 경우에도 값이
//입력되지 않아 -1로 출력된다.
int answer = -1;


void bfs(int N, int number, int sum, int cnt) {
	//최대가 8이므로 9이상일경우 리턴
	if (cnt > 8) return;
	//number와 총합이 같을경우 
	if (sum == number) {
		//우선 cnt와 먼저 입력된 answer값을 비교하여 최소값인지 확인
		//처음 if문에 들어오는경우 answer은 앞선조건과 맞지않아
		//or조건으로 처음의 값인 -1일 경우에도 성립하게 해준다.
		if (cnt < answer || answer == -1) {
			answer = cnt;
		}
		return;
	}

	//맨처음에 입력될값이 N인지? NN인지? NNN인지?
	//최대 N의 사용횟수가 8까지 이므로 조건문 완성
	//ar에 N의 숫자만 사용한다는 조건을 성립한 *의 값
	int ar = 0;
	for (int i = 0; i < 8; i++) {
		ar = ar * 10 + N;// i=0 -> N, i=1 -> NN, i=2 -> NNN .....

		//cnt+1+i는 i가 0부터 시작되므로 ar이 N일경우에도 +1을 해주기위한 방법
		bfs(N, number, sum + ar, cnt + 1 + i);
		bfs(N, number, sum - ar, cnt + 1 + i);
		bfs(N, number, sum / ar, cnt + 1 + i);
		bfs(N, number, sum * ar, cnt + 1 + i);
	}
}


int solution(int N, int number) {
	bfs(N, number, 0, 0);
	return answer;
}

int main() {
	int N = 5;
	int number = 12;
	cout << solution(N, number);
	return 0;
}