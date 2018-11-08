// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*문제6 Cospro
체스에서 나이트(knight)는 아래 그림과 같이 동그라미로 표시된 8개의 방향중 한 곳으로 한 번에 이동이 가능합니다.단, 나이트는 체스판 밖으로는 이동할 수 없습니다. 체스판의 각 칸의 위치는 다음과 같이 표기합니다.예를 들어, A번줄과 1번줄이 겹치는 부분은 'A1'이라고 합니다.
나이트의 위치 pos가 매개변수로 주어질 때, 나이트를 한 번 움직여서 이동할 수 있는 칸은 몇개인지 return 하도록
solution 함수를 완성해주세요.
-매개변수 설명-
나이트의 위치 pos가 solution 함수의 매개변수로 주어집니다. * pos는 A부터 H까지의 대문자 알파벳 하나와 1 이상 8이
하의 정수 하나로 이루어진 두 글자 문자열입니다. * 잘못된 위치가 주어지는 경우는 없습니다.
*/


//1~8까지 행
//A~H까지 열 
//깊이우선 BFS
int solution(string pos) {
	// 여기에 코드를 작성해주세요.
	int answer = 0;
	//체스 나이트 이동 
	int move_col[] = { 2,2,-2,-2,1,-1,1,-1 };//y축  
	int move_row[] = { 1,-1,1,-1,2,2,-2,-2 };//x축
	int col = 0;
	int row = 0;
	
	//행열 크기 구하기
	for (char a = '1'; a <= pos.at(1); a++) {
		col++;
	}
	for (char a = 'A'; a <=pos.at(0) ; a++) {
		row++;
	}
	
	for (int i = 0; i < 8; i++) {
		col += move_col[i];
		row += move_row[i];
		if (col >= 0 && col < 8 && row >= 0 && row<8) {
			answer++;
		}
	}

	return answer;

	
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	string pos = "A7";
	int ret = solution(pos);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}