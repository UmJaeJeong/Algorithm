// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//나이트가 위치한 곳에서 몇군데나 갈수 있는지 확인;
int x[8] = { 1,2,2,1,-1,-2,-2,-1 };
int y[8] = { 2,1,-1,-2,-2,-1,1,2 };

//a,b,c,d,e,f,g,h
int solution(string pos) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
	//x축 알파벳
	int a = pos[0] - 'A'+1;

	//y축 숫자
	int b = pos[1] - 48;
	cout << b << ' ' << a << endl;
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << a + x[i] << ' ' << b + y[i] << endl;
		if (a + x[i] > 0 && a + x[i] <= 8 && b + y[i] > 0 && b + y[i] <= 8) answer++;
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