#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/* 단어정렬 1181문제
문제: 
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램 작성

입력 : 
첫째 줄에 단어의 개수 N이 주어진다. 
(1≤N≤20,000) 둘째 줄부터 N개의 줄에 걸쳐 
알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 
주어지는 문자열의 길이는 50을 넘지 않는다.

*/
int number;
string a[20001];

bool compare(string a, string b) {
	if (a.length() < b.length()) return 1;
	else if (a.length()>b.length()) return  0;
	else return a < b;
}

int main(void) {
	
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> a[i];
	}
	
	sort(a, a + number,compare);
	for (int i = 0; i < number; i++) {
		if(a[i]!=a[i+1])
		cout << a[i] << endl;
	}
	return 0;
}