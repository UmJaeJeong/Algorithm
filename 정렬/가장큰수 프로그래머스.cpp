#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
//두문자열을 합하여 어느것이 큰지 비교
bool compare(string a, string b) {
	return (a + b>b + a) ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;
	for (int i = 0; i<numbers.size(); i++) {
		str.push_back(to_string(numbers[i]));//정수를 문자열로 변환하여 추가
	}
	sort(str.begin(), str.end(), compare);
	for (int i = 0; i<str.size(); i++) answer += str[i];
	//맨앞의 인덱스에 0이 나오면 모두 0이므로 
	if (answer[0] == '0') return "0";
	return answer;
}