#include<iostream>
#include<vector>


using namespace std;
/*�켱 ù��° ������ Ǯ��� H��° ����T���ڱ��� ���׻� psum[H-1] = psum[]*/

//�κ��� �Լ�
int MOD = 200911011;

vector<int> PartialSum(vector<int>& number) {
	//0���� ���� ���� 0���� �����Ͽ� ����ó���� ����
	vector<int> psum(number.size() + 1, 0);

	for (int i = 1; i <= number.size(); i++) {
		psum[i] = (psum[i - 1] + number[i - 1]) % MOD;
	}

	return psum;
}



int BuyToWay(const vector<int>& psum, int k) {
	vector<int> Modpsum(psum.size(), 0);
	vector<long long> count(k, 0);

	//%k�� ����߱⶧���� Modpsum�� ���� ��� k���� �۴�
	for (int i = 0; i < psum.size(); i++) {
		Modpsum[i] = psum[i] % k;
	}

	for (int j = 0; j < Modpsum.size(); j++) {
		count[Modpsum[j]]++;
	}

	int ret = 0;
	for (int i = 0; i < count.size(); i++) {
		if (count[i] >= 2)
			ret = (ret + (count[i] * (count[i] - 1)) / 2) % MOD;   // 2�� �̻��� ��� Combinaition�� ����ؼ� 2������ �̴� Ȯ���� ���
	}

	return ret;
}

void main() {
	vector<int> number;
	for (int i = 1; i < 7; i++) {
		number.push_back(i);
	}


	//�κ���
	vector<int> psum = PartialSum(number);
	cout << "�ѹ��� �ֹ��� ��� : " << BuyToWay(psum, 4) << endl;;

}