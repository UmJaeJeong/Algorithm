#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAX 50001


int solution(vector<int> people, int limit) {
	int length = people.size();
	int answer = length;
	if (people.size() == 1)return answer = 1;
	sort(people.begin(), people.end());
	int s_idx = 0;
	int d_idx = length - 1;
	int cnt = 0;


	while (s_idx<d_idx) {
		if (people[s_idx] + people[d_idx] <= limit) {
			s_idx++;
			d_idx--;
			cnt++;
		}
		else {
			d_idx--;
		}
	}

	return answer - cnt;
}

int main() {
	vector<int> people;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		people.push_back(x);
	}
	int limit = 0;
	cin >> limit;

	cout<<solution(people, limit);
	return 0;
}