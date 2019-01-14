#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
�� ��� ���� 100������ ��� ���� ����
���߼ӵ��� �ٸ��⶧���� ��ɼ����� ���ִ°��� �� ���� ���ߵɼ��� ����
�۾������� ���� ���� �迭 progress
�۾��ӵ��� ���� ���� �迭 speeds
�� �������� ��� ����� �����Ǵ���???

������ �Ϸ翡 �ѹ��� ����, �Ϸ��� ���� �̷����ٰ� ����
�������� 95�� �Ϸ翡 4%��� 2�ϵڿ����� 
1.93�۴� �Ϸ翡1�� 7�ϰ� �۾� �� ����
2.30�� �Ϸ� �Ϸ翡 30���۾� 3�ϵڿ� ����

ù��° �Ⱓ ~ ù�������� ���ų� ������ �� ���� 
�״��� ū�ͺ��� ~ 
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