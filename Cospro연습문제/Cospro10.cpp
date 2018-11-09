#include <iostream>
#include <vector>]
#include <algorithm>
using namespace std;
/*문제10 Cospro
지난 연속된 n일 동안의 주식 가격이 순서대로 들어있는 배열이 있습니다. 이때, 다음 규칙에 따라 주식을 사고 팔았을 때의
최대 수익을 구하려 합니다.
n일 동안 주식을 단 한 번 살 수 있습니다.
n일 동안 주식을 단 한 번 팔 수 있습니다.
주식을 산 날에 바로 팔 수는 없으며, 최소 하루가 지나야 팔 수 있습니다.
적어도 한 번은 주식을 사야하며, 한 번은 팔아야 합니다.

주식을 팔 때는 반드시 이전에 주식을 샀어야 하며, 최대 수익은 양수가 아닐 수도 있습니다.
연속된 n 일 동안의 주식 가격이 순서대로 들어있는 배열 prices가 매개변수로 주어질 때, 주식을 규칙에 맞게 한 번만 사고
팔았을 때 얻을 수 있는 최대 수익을 return 하도록 solution 함수를 작성했습니다. 그러나, 코드 일부분이 잘못되어있기 때
문에, 코드가 올바르게 동작하지 않습니다. 주어진 코드에서 한 줄만 변경해서 모든 입력에 대해 올바르게 동작하도록 수정
해주세요.
*/
int solution(vector<int> prices) {
	int INF = 1000000001;//prices의 길이 최대치
	int tmp = INF;
	int answer = -INF;
	for (int price : prices) {
		if (tmp != INF)//첫번째때 팔지 못하게
			answer= max(answer, price- tmp);
		tmp= min(tmp, price);//첫번재 값의 최소  tmp가 초기에 최댓값이기때문에
	}
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
	vector<int> prices1 = { 1, 2, 3 };
	int ret1 = solution(prices1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> prices2 = { 3, 1 };
	int ret2 = solution(prices2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}