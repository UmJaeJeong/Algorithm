#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*문제8 Cospro
1번부터 N번까지 후보에 대해서 투표를 진행했습니다. 예를 들어 투표 결과가 [1, 5, 4, 3, 2, 5, 2, 5, 5, 4]라면 순서대로
[1번, 5번, 4번, 3번, 2번, 5번, 2번, 5번, 5번, 4번] 후보에 투표했음을 나타냅니다. 이때, 가장 많은 표를 받은 후보의 번호
를 구하려고 합니다.
주어진 solution 함수는 후보의 수 N과 투표를 진행한 결과가 담긴 배열 votes가 매개변수로 주어졌을 때, 가장 많은 표를
받은 후보의 번호를 return 하는 함수입니다. 그러나, 코드 일부분이 잘못되어있기 때문에, 몇몇 입력에 대해서는 올바르게
동작하지 않습니다. 주어진 코드에서 한 줄만 변경해서 모든 입력에 대해 올바르게 동작하도록 수정하세요.
*/

vector<int> solution(int N, vector<int> votes) {
	int vote_counter[11] = { 0 }; //최대 후보자가 10명 배열0번째는 사용하지 않음
	for (int i = 0; i < votes.size(); i++) {//후보자의 표수 기록
		vote_counter[votes[i]] += 1;
	}
	int max_val = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {//가장 많은 수의 투표를 받은 후보자와 그 후보자의 인원
		if (max_val < vote_counter[i]) {
			max_val = vote_counter[i];
			cnt = 1;
		}
		else if (max_val == vote_counter[i]) {
			cnt += 1;
		}
	}

	vector<int> answer(cnt, 0);
	for (int i = 1, idx = 0; i <= N; i++) { //maxim과 같은거 고르기 같은 수 포함
		if (vote_counter[i] == max_val) {
			answer[idx] = i;
			idx += 1;
		}
	}
	return answer;
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
	int N1 = 5;
	vector<int> votes1 = { 1,5,4,3,2,5,2,5,5,4 };
	vector<int> ret1 = solution(N1, votes1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {";
	for (int i = 0; i < ret1.size(); i++) {
		if (i != 0) cout << ", ";
		cout << ret1[i];
	}
	cout << "} 입니다." << endl;

	int N2 = 4;
	vector<int> votes2 = { 1,3,2,3,2 };
	vector<int> ret2 = solution(N2, votes2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {";
	for (int i = 0; i < ret2.size(); i++) {
		if (i != 0) cout << ", ";
		cout << ret2[i];
	}
	cout << "} 입니다." << endl;
}