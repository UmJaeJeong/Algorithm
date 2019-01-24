#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	//first���� second ���ȣ 
	queue<pair<int, int>> q;
	//���ȣ�� ������ pair�� ���� q�� ����
	for (int i = 0; i<priorities.size(); i++) {
		q.push(pair<int, int>(priorities[i], i));
	}
	int length = priorities.size();
	//�켱������ ������ ���� �ϱ����� ������ �켱���� �������� ����
	//������ ����� ����Ұ�
	sort(priorities.begin(), priorities.end());


	while (!q.empty()) {
		//�Ǿ��� ���� ����
		pair<int, int> p = q.front();
		q.pop();
		//�װ��� �켱������ ���� �������� ���
		if (p.first == priorities[length - 1]) {
			//���� ����
			answer++;
			//�״��� �켱������ ���� ��
			length--;
			//���ϴ� ������ ����� break;
			if (location == p.second) {
				break;
			}
		}
		else {  //�켱������ ���� �����Ͱ� �ƴҰ��
			q.push(p);//�տ��� ����� �����͸� �ǵڷ� �ٽ� ����
		}
	}

	return answer;
}