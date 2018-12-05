#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���ī�� �˰��� ==> �׻� �������� ������ �Ϲ����� ���
//						������ �۵��ϴ� ������ ������ ���ڿ� ��Ī �˰���
//						���ڿ��� �ؽ����� ���Ͽ� ���� ������ ���ϴ� �˰��� 

/*
Ư¡:
�ؽñ���� ��� ��,�Ϲ������� �� �����͸� �װ��� ��¡�ϴ� ª�� �����ͷ� �ٲپ��ִ� ���
�ܼ��� ���  �ð����⵵�� O(1)�Ͽ� ��������.

�ؽ��� �浹�� �ִ� ��쵵 ������ �ſ� ����
����, �浹�� �Ͼ�� ��� �����͸� �̿��Ͽ� �����ڷᱸ���� �ذ��Ҽ� �ִ�.
*/

void findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;

	for (int i = 0; i <= parentSize - patternSize; i++) {
		//0�ϰ�� ��ó������ 
		if (i == 0) {
			//pattern�� �ؽ����� stirng�� �պκ� �ؽ����� ����
			for (int j = 0; j < patternSize; j++) {
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power *= 2;
			}
		}
		//parent�� string�� �պκ��� ���� �޺κ��� 1�� �߰��ϸ鼭 Ȯ��
		else {
			//�տ� ���ϱ�2�ϴ� ������ ���� ���� ������ ���ε��� ���� 2��0�� �ڸ��� �����ϹǷ�
			//�������� ��� 1�¾� �÷���� �ȴ�.
			//��� �ؽ��� = 2*(���� �ؽð� - ����տ� �ִ� ���ڼ���)+���Ӱ� ���� ���� ����
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}
		if (parentHash == patternHash) {
			bool finded = true;
			//���ڿ��� ������ �ϳ��� �� ��
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
				}
			}
			if (finded) {
				cout << i + 1 << "��°���� �߰�" << endl;
			}
		}
	}
}

int main() {
	string parent = "aaababacabacaaabacaaaba";
	string pattern = "aaa";
	findString(parent, pattern);
	return 0;
}