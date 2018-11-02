#include<iostream>
using namespace std;

//�ش��������
//(������ ���Ҹ� �ϳ��̻��� �߰��ϸ� �ϱ׷����� ����)
#define  MAXN 30

//������ ũ�Ⱑ ������ ��Ʈ����ũ�� ���
int n;
//explodes[i]�� i�� ���� �ξ��� �� �����ϴ� ���� ������ ��Ʈ����ũ ǥ��
int explodes[MAXN];


bool isStable(int set) {
	for (int i = 0; i < n; i++)//���տ� ���Ե� i���� ���ҿ� ���� �ξ����� �����ϴ� ������ set�� �ִٸ� 
		if ((set &(1 << i)) && (set & explodes[i]))
			return false;
	return true;
}


//��� �ش� ���� ������ ���� ����
int countStablesSet() {
	int ret = 0;
	//��� ������ ����
	for (int set = 1; set < (1 << n); set++) {
		//�켱 �������� �ƴ϶�� �� �ʿ䰡 ����.
		if (!isStable(set)) continue;
		//�ش� ���� �������� Ȯ���ϱ� ����, ���� �� �ִ� �ٸ� ������ �ֳ� Ȯ��
		bool canExtend = false;
		for(int add = 0;add<n;add++)
			//add�� ���տ� ���ԵǾ� ���� �ʰ�, set�� add�� �־ �������̶��
			if ((set &(1 << add)) == 0 && (explodes[add] & set) == 0) {
				canExtend = true;
				break;
			}
		if (!canExtend)
			ret++;
	}
	return ret;
}

void main() {
	for (int i = 0; i < 10; i++)
		cout << ((10 & (2 << i)) && (10 & (2 << i))) << endl;
}