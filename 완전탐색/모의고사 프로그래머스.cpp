#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int a[5] = { 1,2,3,4,5 };
int b[8] = { 2,1,2,3,2,4,2,5 };
int c[10] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int cnt[4] = { 0, };
	for (int i = 0; i<answers.size(); i++) {
		if (answers[i] == a[i % 5])cnt[1]++;
		if (answers[i] == b[i % 8])cnt[2]++;
		if (answers[i] == c[i % 10])cnt[3]++;
	}
	int max = 0;
	for (int i = 1; i <= 3; i++) {
		if (max<cnt[i]) max = cnt[i];
	}
	for (int i = 1; i <= 3; i++) {
		if (max == cnt[i])answer.push_back(i);
	}
	sort(answer.begin(), answer.end());
	return answer;
}