#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(string name) {
	int answer = 0;
	int cnt = 0;
	int cnt1 = 0;
	int len = name.size();

	//��� A�� ��� 
	for (int i = 0; i<name.size(); i++) {
		if (name[i] == 'A')answer++;
	}
	if (answer == len) return 0;

	//��ó�� Ŀ����ġ�� ����
	if (name[0] - 'A' <= 13) {//���� ���ĺ����� Ƚ���� ���� �ּ�
		cnt = cnt1 = name[0] - 'A';
	}
	else {//���� ���ĺ����� Ƚ���� ���� �ּ�
		cnt = cnt1 = 'Z' - name[0] + 1;
	}

	//Ŀ���� ���������� 
	for (int i = 1; i<len; i++) {
		cnt++;  //Ŀ���̵� 1����

		if (name[i] - 'A' <= 13) {//�������ĺ����� �Ҷ� Ƚ���� �ּ�
			cout << name[i] - 'A' << endl;
			cnt += name[i] - 'A';
		}
		else {//���� ���ĺ����� �Ҷ� Ƚ���� �ּ�
			cout << 'Z' - name[i] + 1 << endl;
			cnt += 'Z' - name[i] + 1;
		}

		bool flag = true;
		//���� i���� �Ŀ� �˻��� �͵��� ��� A�� ���
		for (int j = i + 1; j<len; j++) {
			if (name[j] != 'A') {
				flag = false;
			}
		}
		if (flag) break;

	}

	//Ŀ���� ��������
	for (int i = len - 1; i>0; i--) {
		cnt1++;//Ŀ���̵�

		if (name[i] - 'A' <= 13) {//�������ĺ����� �Ҷ� Ƚ���� �ּ�
			cnt1 += name[i] - 'A';
		}
		else {//�������ĺ����� �Ҷ� Ƚ���� �ּ�
			cnt1 += 'Z' - name[i] + 1;
		}

		bool flag = true;
		//���� i���� �Ŀ� �˻��� �͵��� ��� A�� ���
		for (int j = i - 1; j>0; j--) {
			if (name[j] != 'A') flag = false;
		}
		if (flag) break;

	}
	answer = min(cnt, cnt1);//Ŀ���� ���������� �������� ���Ͽ� �ּҰ�

	return answer;
}