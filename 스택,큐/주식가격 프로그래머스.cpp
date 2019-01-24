#include <string>
#include <vector>
#include <algorithm>
#include  <iostream>
using namespace std;
//초 단위로 기록된 주식가격이 담긴 배열prices
//가격이 유지된 기간은 몇초?
//price 1~10000
//길이 2~100000;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	//주식 길이 만큼 반복
	for (int i = 0; i<prices.size(); i++) {
		int cnt = 0;
		//i번쨰의 주식부터 시작하여 비교하기 위해 j=i부터 시작
		for (int j = i; j<prices.size(); j++) {
			//i번쨰의 주식보다 작을경우 또는 j가 마지막일 경우 
			if (prices[i]>prices[j] || j == prices.size() - 1) {
				//cout<<prices[i]<<' '<<prices[j]<<endl;
				cnt = j - i;//유지되는 시간
				break;
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}