#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
문자열 형태의 식을 계산하려 합니다. 식은 2개의 자연수와 1개의 연산자('+', '-', '*' 중 하나)로 이루어져 있습니다. 예를 들
어 주어진 식이 "123+12"라면 이를 계산한 결과는 135입니다.
문자열로 이루어진 식을 계산하기 위해 다음과 같이 간단히 프로그램 구조를 작성했습니다.
---------------------------------------------------------------------
1단계. 주어진 식에서 연산자의 위치를 찾습니다.
2단계. 연산자의 앞과 뒤에 있는 문자열을 각각 숫자로 변환합니다.
3단계. 주어진 연산자에 맞게 연산을 수행합니다.
---------------------------------------------------------------------
문자열 형태의 식 expression이 매개변수로 주어질 때, 식을 계산한 결과를 return 하도록 
solution 함수를 작성하려 합니다. 
위 구조를 참고하여 코드가 올바르게 동작할 수 있도록 
빈칸에 주어진 funca, funcb, func_c 함수와 매개변수를 알맞게 채워주세요.
문자열 형태의 식 expression이 solution 함수의 매개변수로 주어집니다. 
* expression은 연산자 1개와 숫자 2개가 결합
한 형태입니다. * 연산자는 '+', '-', '*'만 사용됩니다.
* 숫자는 1 이상 10,000 이하의 자연수입니다.
*/
class Pair{
    public:
    int first_num;
    int second_num;
};

//정수변환 후 연사자를 사용한 값 구함
int func_a(int numA, int numB, char exp){
    if (exp == '+')
        return numA + numB;
    else if (exp == '-')
        return numA - numB;
    else
        return numA * numB;
}

//연산부분 index 찾기
int func_b(string exp){
    for(int i = 0; i < exp.length(); i++){
        char e = exp[i];
        if(e == '+' || e == '-' || e == '*')
            return i;
    }
    return -1;
}

//문자열 -> 정수로 전환
Pair func_c(string exp, int idx){
    Pair ret;
    ret.first_num = stoi(exp.substr(0, idx));
    ret.second_num = stoi(exp.substr(idx+1));
    return ret;
}

int solution(string expression) {
    int exp_index = func_b(expression);
    Pair numbers = func_c(expression, exp_index);
    int result = func_a(numbers.first_num, numbers.second_num, expression[exp_index]);
    return result;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string expression = "123+12";
    int ret = solution(expression);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << ret << endl;
}