#include <string>
#include <vector>
#include <algorithm>
#include  <iostream>
using namespace std;
//�� ������ ��ϵ� �ֽİ����� ��� �迭prices
//������ ������ �Ⱓ�� ����?
//price 1~10000
//���� 2~100000;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	//�ֽ� ���� ��ŭ �ݺ�
	for (int i = 0; i<prices.size(); i++) {
		int cnt = 0;
		//i������ �ֽĺ��� �����Ͽ� ���ϱ� ���� j=i���� ����
		for (int j = i; j<prices.size(); j++) {
			//i������ �ֽĺ��� ������� �Ǵ� j�� �������� ��� 
			if (prices[i]>prices[j] || j == prices.size() - 1) {
				//cout<<prices[i]<<' '<<prices[j]<<endl;
				cnt = j - i;//�����Ǵ� �ð�
				break;
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}