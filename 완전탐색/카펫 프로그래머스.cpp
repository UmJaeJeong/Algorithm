#include <string>
#include <vector>
#include<cmath>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int sum = brown + red;
	int limit = (int)sqrt(sum);
	for (int col = 3; col <= limit; col++) {
		if (sum%col == 0) {
			int row = sum / col;
			if ((col - 2)*(row - 2) == red) {
				answer.push_back(row);
				answer.push_back(col);
				break;
			}

		}
	}
	return answer;
}