#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/*
DNA�� ���� 4������ ƩŬ����Ƽ��� �̿���� �ִ�. ATGC
�츮�� ��� ������ ǥ���� �� DNA�̸� �̷�� ��Ŭ����Ƽ���� ù���ڸ� ���� ǥ��

*/
//TACG �װ��� ������
#define MAX 1001
string a[MAX];
string answer;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	//�عְŸ� ���ϱ�
	int result = 0;
	for (int i = 0; i < m; i++) {
		sort(a, a + n);

		int j = 0;
		int count[4] = { 0, };

		while (a[j][i] == 'A') {
			count[0]++; j++;
		}
		while (a[j][i] == 'C') {
			count[1]++; j++;
		}
		while (a[j][i] == 'G') {
			count[2]++; j++;
		}
		while (a[j][i] == 'T') {
			count[3]++; j++;
		}

		int min = 0;
		int index = 0;
		for (int k = 0; k < 4; k++) {
			if (min < count[k]) {
				min = count[k];
				index = k;
			}
		}

		if (index == 0) answer += 'A';
		if (index == 1) answer += 'C';
		if (index == 2) answer += 'G';
		if (index == 3) answer += 'T';

		result += (n - count[index]);
		for (int k = 0; k < n; k++) {
			a[k][i] = '0';
		}

	}

	cout << answer << endl;
	cout << result << endl;

	 
	return 0;
}