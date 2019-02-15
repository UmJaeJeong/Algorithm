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
	set<int> s;//set�� ����Ͽ� �ߺ��Ǵ� �� ����X
	sort(numbers.begin(), numbers.end());
	do {
		for (int i = 1; i <= numbers.size(); i++) {
			string str = numbers.substr(0, i);
			if (a[stoi(str)] == 0) {
				s.insert(stoi(str));
			}
		}
	} while (next_permutation(numbers.begin(), numbers.end()));	//next_permutation�Լ� �˱� �𸥴ٸ� �����ϴ� �Լ��� ��������
	return answer = s.size();
}