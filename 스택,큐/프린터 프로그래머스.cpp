#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	//first순위 second 방번호 
	queue<pair<int, int>> q;
	//방번호와 순위를 pair를 통해 q에 삽입
	for (int i = 0; i<priorities.size(); i++) {
		q.push(pair<int, int>(priorities[i], i));
	}
	int length = priorities.size();
	//우선순위가 높은것 부터 하기위해 기존의 우선순위 오름차순 정렬
	//마지막 방부터 사용할것
	sort(priorities.begin(), priorities.end());


	while (!q.empty()) {
		//맨앞의 값을 추출
		pair<int, int> p = q.front();
		q.pop();
		//그값의 우선순위와 같은 데이터일 경우
		if (p.first == priorities[length - 1]) {
			//순위 증가
			answer++;
			//그다음 우선순위를 가진 값
			length--;
			//원하는 데이터 추출시 break;
			if (location == p.second) {
				break;
			}
		}
		else {  //우선순위가 같은 데이터가 아닐경우
			q.push(p);//앞에서 퇴출된 데이터를 맨뒤로 다시 삽입
		}
	}

	return answer;
}