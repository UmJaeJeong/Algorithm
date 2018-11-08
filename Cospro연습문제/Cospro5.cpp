// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*문제5번 Cospro5
다음과 같이 n x n 크기의 격자에 1부터 n x n까지의 수가 하나씩 있습니다.이때 수가 다음과 같은 순서로 배치되어있다면 이것을 n-소용돌이 수라고 부릅니다.소용돌이 수에서 1행 1열부터 n 행 n 열까지 대각선상에 존재하는 수들의 합을 구해야 합니다.위의 예에서 대각선상에 존재하는 수의 합은 15입니다. 격자의 크기 n이 주어질 때 n-소용돌이 수의 대각선상에 존재하는
수들의 합을 return 하도록 solution 함수를 완성해주세요.
*/
int solution(int n) {
	// 여기에 코드를 작성해주세요.
	int answer = 0;
	int an[100][100] = {};
	int turn = 1;
	int value = 1;
	int max = n;
	int x = 0;
	int y = -1;

	while (n >= 0) {
		//행
		for (int i = 0; i < n; i++) {
			y = y + turn;
			an[x][y] = value;
			value++;
		}
		n--;

		for (int j = 0; j < n; j++) {
			x = x + turn;
			an[x][y] = value;
			value++;
		}
		turn *= -1;
	}

	for (int i = 0; i < max; i++) {
		answer += an[i][i];
	}
	
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int n1 = 3;
	int ret1 = solution(n1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int n2 = 2;
	int ret2 = solution(n2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}