#include<iostream>
#include<vector>


using namespace std;
/*우선 첫번째 문제를 풀어보면 H번째 부터T상자까지 주항상 psum[H-1] = psum[]*/

//부분합 함수
int MOD = 200911011;

vector<int> PartialSum(vector<int>& number) {
	//0번쨰 방의 값이 0으로 저장하여 예외처리를 예방
	vector<int> psum(number.size() + 1, 0);

	for (int i = 1; i <= number.size(); i++) {
		psum[i] = (psum[i - 1] + number[i - 1]) % MOD;
	}

	return psum;
}



int BuyToWay(const vector<int>& psum, int k) {
	vector<int> Modpsum(psum.size(), 0);
	vector<long long> count(k, 0);

	//%k를 사용했기때문에 Modpsum의 값은 모두 k보다 작다
	for (int i = 0; i < psum.size(); i++) {
		Modpsum[i] = psum[i] % k;
	}

	for (int j = 0; j < Modpsum.size(); j++) {
		count[Modpsum[j]]++;
	}

	int ret = 0;
	for (int i = 0; i < count.size(); i++) {
		if (count[i] >= 2)
			ret = (ret + (count[i] * (count[i] - 1)) / 2) % MOD;   // 2개 이상일 경우 Combinaition을 사용해서 2가지를 뽑는 확률을 계산
	}

	return ret;
}

void main() {
	vector<int> number;
	for (int i = 1; i < 7; i++) {
		number.push_back(i);
	}


	//부분합
	vector<int> psum = PartialSum(number);
	cout << "한번만 주문할 경우 : " << BuyToWay(psum, 4) << endl;;

}