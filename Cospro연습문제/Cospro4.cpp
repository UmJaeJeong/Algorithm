// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
어느 누군가가 타임머신을 타고 과거로 가서 숫자 0이 없는 수 체계를 전파했습니다. 역사가 바뀌어 이제 사람들의 의식 속
엔 0이란 숫자가 사라졌습니다. 따라서, 현재의 수 체계는 1, 2, 3, ..., 8, 9, 11, 12, ...와 같이 0이 없게 바뀌었습니다.
0을 포함하지 않은 자연수 num이 매개변수로 주어질 때, 이 수에 1을 더한 수를 return 하도록 solution 함수를 완성해주
세요.
*/
long long solution(long long num) {
    // 여기에 코드를 작성해주세요.
    long long answer = 0;
	int count = 0;
	int MOD = 10;
	num++;
	long long value = num;

	while (value != 0) {


	}
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    long long num = 9949999;
    long long ret = solution(num);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << ret << endl;
}