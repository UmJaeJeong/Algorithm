#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;


int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int> q;

	for (int i = 0; i < scoville.size(); i++) {
		q.push(-scoville[i]);
	}


	while (true) {

		int a = -q.top();
		if (a >= K) {
			break;
		}

		if (q.size() == 1) {
			answer = -1;
			break;
		}

		q.pop();
		int b = -q.top();

		q.pop();

		int cand = a + (b * 2);
		q.push(-cand);

		answer++;
	}

	return answer;
}