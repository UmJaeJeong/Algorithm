#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//�̸��� �쿬�� ��Ÿ����� ��� N ��
//30�̶� ���� ����
//N�� ����Ͽ� 30�� ����� �Ǵ� ���� ū�� ���ϱ�
bool compare(char a, char b) {
	return a > b;
}

int main() {
	string n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n.size(); i++) {
		result += n[i] - 48;
	}

	if (n.find("0") == string::npos || result%3!=0) {
		cout << -1 << endl;
		return 0;
	}

	sort(n.begin(), n.end(),compare);
	cout << n << endl;

	return 0;
}
