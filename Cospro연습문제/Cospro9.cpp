#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*문제9 Cospro
두 학생 A와 B는 계단 게임을 하였습니다. 계단 게임의 규칙은 아래와 같습니다.
1. 계단 제일 아래에서 게임을 시작합니다. (0번째 칸)
2. 가위바위보를 합니다.
3. 이기면 계단 세 칸을 올라가고, 지면 한 칸을 내려가고, 비기면 제자리에 있습니다.
4. 계단 제일 아래에서 지면 제자리에 있습니다.
5. 2~4 과정을 열 번 반복합니다.

A와 B가 계단 게임을 완료한 후에, A가 계단 위 몇 번째 칸에 있는지 파악하려고 합니다.
A와 B가 낸 가위바위보 기록이 순서대로 들어있는 배열 recordA와 recordB가 매개변수로 주어질 때, 게임을 마친 후의 A
의 위치를 return 하도록 solution 함수를 작성했습니다. 그러나, 코드 일부분이 잘못되어있기 때문에, 몇몇 입력에 대해서
는 올바르게 동작하지 않습니다. 주어진 코드에서 한 줄만 변경해서 모든 입력에 대해 올바르게 동작하도록 수정하세요.
*/

int func(int record) {//묵찌빠 중 이기는 경우의 같은 값
	if (record == 0) return 1;
	else if (record == 1) return 2;
	return 0;
}

int solution(vector<int> recordA, vector<int> recordB) {
	int cnt = 0;
	for (int i = 0; i < (int)recordA.size(); i++) {
		if (recordA[i] == recordB[i])  //비겼을 경우
			continue;
		else if (recordA[i] == func(recordB[i]))  //이겼을 경우
			cnt = cnt + 3;
		else 
			cnt = max(0,cnt - 1); //졌을 경우 현재 cnt == 0일 경우 내려가지 못한다는것이 없음
	}
	return cnt;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
	vector<int> recordA = { 2,0,0,0,0,0,1,1,0,0 };
	vector<int> recordB = { 0,0,0,0,2,2,0,2,2,2 };
	int ret = solution(recordA, recordB);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}