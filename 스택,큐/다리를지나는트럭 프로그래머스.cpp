#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int sum = 0;

	//������ Ʈ������ �����ϱ����� ť ���
	queue<int> q;
	for (int i = 0; i<truck_weights.size(); i++) {
		int t_w = truck_weights[i];
		while (true) {
			//�ٸ��� ������ Ʈ���� ������� ���� 
			if (q.empty()) {
				q.push(t_w);
				answer++;
				sum += t_w;
				break;
			}
			else if (q.size() == bridge_length) {//Ʈ���� ����� �ٸ����� �������
				sum -= q.front();//1�뾿 ���� �״����� ������ Ʈ���� ���Ե� ����ϱ����� ���
				q.pop();
			}
			else {
				if (sum + t_w>weight) {//����ٸ����� Ʈ���� ����Ʈ���� ���� �ջ��� �ִ빫�԰� ������
					q.push(0);      //�������� �����ϱ� ���� 0�� ���� ����
					answer++;
				}
				else {
					q.push(t_w);    //����ٸ����� Ʈ�����԰� �ʰ����Ը� ���� �ʾҴٸ� ����Ʈ�� ����
					answer++;
					sum += t_w;
					break;
				}
			}
		}
	}
	//+bridge_length�� ���ִ� ���� : �������� Ʈ���� ���� �� ����������
	//�ð��� �߰����ش� Ʈ���� 1�ʿ� ����1��ŭ �����̹Ƿ�
	//bridge_length�� ������
	return answer + bridge_length;
}