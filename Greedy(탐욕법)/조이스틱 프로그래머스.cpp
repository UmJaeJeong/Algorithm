#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(string name) {
	int answer = 0;
	int cnt = 0;
	int cnt1 = 0;
	int len = name.size();

	//모두 A일 경우 
	for (int i = 0; i<name.size(); i++) {
		if (name[i] == 'A')answer++;
	}
	if (answer == len) return 0;

	//맨처음 커서위치의 문자
	if (name[0] - 'A' <= 13) {//다음 알파벳으로 횟수가 가장 최소
		cnt = cnt1 = name[0] - 'A';
	}
	else {//이전 알파벳으로 횟수가 가장 최소
		cnt = cnt1 = 'Z' - name[0] + 1;
	}

	//커서가 오른쪽으로 
	for (int i = 1; i<len; i++) {
		cnt++;  //커서이동 1증가

		if (name[i] - 'A' <= 13) {//다음알파벳으로 할때 횟수가 최소
			cout << name[i] - 'A' << endl;
			cnt += name[i] - 'A';
		}
		else {//이전 알파벳으로 할때 횟수가 최수
			cout << 'Z' - name[i] + 1 << endl;
			cnt += 'Z' - name[i] + 1;
		}

		bool flag = true;
		//현재 i보다 후에 검색할 것들이 모두 A일 경우
		for (int j = i + 1; j<len; j++) {
			if (name[j] != 'A') {
				flag = false;
			}
		}
		if (flag) break;

	}

	//커서가 왼쪽으로
	for (int i = len - 1; i>0; i--) {
		cnt1++;//커서이동

		if (name[i] - 'A' <= 13) {//다음알파벳으로 할때 횟수가 최소
			cnt1 += name[i] - 'A';
		}
		else {//이전알파벳으로 할때 횟수가 최소
			cnt1 += 'Z' - name[i] + 1;
		}

		bool flag = true;
		//현재 i보다 후에 검색할 것들이 모두 A일 경우
		for (int j = i - 1; j>0; j--) {
			if (name[j] != 'A') flag = false;
		}
		if (flag) break;

	}
	answer = min(cnt, cnt1);//커서가 오른쪽으로 왼쪽으로 비교하여 최소값

	return answer;
}