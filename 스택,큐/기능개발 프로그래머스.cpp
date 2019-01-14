#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
각 기능 진도 100프로일 경우 서비스 가능
개발속도가 다르기때문에 기능순서가 뒤있는것이 더 빨리 개발될수도 있음
작업진도가 적히 정수 배열 progress
작업속도가 적힌 정수 배열 speeds
각 배포마다 몇개의 기능이 배포되는지???

배포는 하루에 한번만 가능, 하루의 끝에 이러진다고 가정
진도율이 95퍼 하루에 4%라면 2일뒤에배포 
1.93퍼는 하루에1퍼 7일간 작업 후 배포
2.30퍼 완료 하루에 30퍼작업 3일뒤에 배포

첫번째 기간 ~ 첫번쨰보다 같거나 작은것 다 포함 
그다음 큰것부터 ~ 
*/
#define MAX 101
int a[MAX];

// 7(100-pro) = ()1*x
vector<int> solution(vector<int> progresser, vector<int> speeds) {
	vector<int> answer;
	int length = progresser.size();
	for (int i = 0; i < length; i++) {
		int add = 0;
		if ((100 - progresser[i]) % speeds[i] != 0) add = 1;
		a[i] = ((100 - progresser[i])/speeds[i])+add;
	}

	int standard = a[0];
	int cnt = 0;
	// 7 3 9
	for (int i = 0; i < length; i++) {
		if (a[i] <= standard) {
			cnt++;
			if (i == length - 1)answer.push_back(cnt);
		}
		else {
			answer.push_back(cnt);
			standard = a[i];
			cnt = 1;
			if (i == length - 1)answer.push_back(cnt);
		}
		
	}
	return answer;
}
int main() {
	vector<int> progresser;
	vector<int> speeds;

	progresser.push_back(93);
	progresser.push_back(30);
	progresser.push_back(55);

	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);
	vector<int> answer = solution(progresser, speeds);
	cout << endl;
	for (int i = 0; i < answer.size(); i++) {
		if(i!=answer.size()-1)
		cout << answer[i] << ',';
		else  cout << answer[i];
	}
	return 0;
}