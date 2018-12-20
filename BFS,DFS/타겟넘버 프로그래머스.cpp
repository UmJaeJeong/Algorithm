#include <string>
#include <vector>
#include<iostream>

using namespace std;
int cnt;
void DFS(vector<int> number, int target, int sum, int index) {
	if (index == number.size()) {
		if (sum == target) cnt++;
		return;
	}
	DFS(number, target, sum + number[index], index + 1);
	DFS(number, target, sum - number[index], index + 1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	DFS(numbers, target, numbers[0], 0);
	DFS(numbers, target, -1 * numbers[0], 0);
	answer = cnt;
	cout << cnt << endl;
	return answer;
}