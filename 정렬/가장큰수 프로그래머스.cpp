#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
//�ι��ڿ��� ���Ͽ� ������� ū�� ��
bool compare(string a, string b) {
	return (a + b>b + a) ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;
	for (int i = 0; i<numbers.size(); i++) {
		str.push_back(to_string(numbers[i]));//������ ���ڿ��� ��ȯ�Ͽ� �߰�
	}
	sort(str.begin(), str.end(), compare);
	for (int i = 0; i<str.size(); i++) answer += str[i];
	//�Ǿ��� �ε����� 0�� ������ ��� 0�̹Ƿ� 
	if (answer[0] == '0') return "0";
	return answer;
}