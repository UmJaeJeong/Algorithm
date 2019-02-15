#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
#define Max 10000000
int a[Max];

void isPrime() {
	for (int i = 2; i <= sqrt(Max); i++) {
		for (int j = i + i; j <= Max; j += i) {
			if (a[j] == 1)continue;
			if (a[j] == 0) a[j] = 1;
		}
	}
}

int solution(string numbers) {
	isPrime();
	a[0] = 1, a[1] = 1;
	int answer = 0;
	set<int> s;//set을 사용하여 중복되는 수 저장X
	sort(numbers.begin(), numbers.end());
	do {
		for (int i = 1; i <= numbers.size(); i++) {
			string str = numbers.substr(0, i);
			if (a[stoi(str)] == 0) {
				s.insert(stoi(str));
			}
		}
	} while (next_permutation(numbers.begin(), numbers.end()));	//next_permutation함수 알기 모른다면 조합하는 함수를 만들어야함
	return answer = s.size();
}