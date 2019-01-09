#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int length = heights.size() - 1;
	vector<int> q;

	for (int i = length; i >= 0; i--) {
		bool check = false;
		for (int j = i - 1; j >= 0 && check == false; j--) {
			if (heights[i]<heights[j]) {
				q.push_back(j + 1);
				check = true;
				break;
			}
		}
		if (!check) q.push_back(0);
	}

	for (int i = q.size() - 1; i >= 0; i--) {
		answer.push_back(q[i]);
	}

	return answer;
}