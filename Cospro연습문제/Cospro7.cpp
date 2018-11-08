#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*문제7 Cospro
오름차순으로 정렬되어있는 두 배열 arrA, arrB를 하나의 배열로 합치려 합니다. 단, 합친 후의 배열도 오름차순으로 정렬
되어 있어야 합니다.
예를 들어 arrA = [-2, 3, 5, 9], arrB = [0, 1, 5]인 경우 두 배열을 오름차순으로 정렬된 하나의 배열로 합치면 [-2, 0, 1, 3,
5, 5, 9]가 됩니다.
오름차순으로 정렬된 두 배열 arrA와 arrB가 주어졌을 때, 두 배열을 오름차순으로 정렬된 하나의 배열로 합쳐서 return 하
도록 solution 함수를 작성하려 합니다. 빈칸을 채워 전체 코드를 완성해주세요.*/

vector<int> solution(vector<int> arrA, vector<int> arrB) {
	int arrA_idx = 0, arrB_idx = 0;
	int arrA_len = arrA.size();
	int arrB_len = arrB.size();
	vector<int> answer;

	while (arrA_idx < arrA_len && arrB_idx < arrB_len){
		if (arrA[arrA_idx] < arrB[arrB_idx]) {
			answer.push_back(arrA[arrA_idx++]);
		}
		else {
			answer.push_back(arrB[arrB_idx++]);
		}
	}

	while (arrA_idx < arrA_len)
		answer.push_back(arrA[arrA_idx++]);
	while (arrB_idx < arrB_len)
		answer.push_back(arrB[arrB_idx++]);
	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	vector<int> arrA = { -2, 3, 5, 9 };
	vector<int> arrB = { 0, 1, 5 };
	vector<int> ret = solution(arrA, arrB);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 {";
	for (int i = 0; i < ret.size(); i++) {
		if (i != 0) cout << ", ";
		cout << ret[i];
	}
	cout << "} 입니다." << endl;
}