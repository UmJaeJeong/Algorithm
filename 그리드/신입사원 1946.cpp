#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//�����ɻ� ������ �������� ���� �� ��� �ϳ��� �ٸ� �����ں��� ������

int main() {

	int t;
	cin >> t;
	vector<int> answer;

	while (t-- > 0) {
		vector<pair<int, int>> a;
		int result = 0;
		int n;
		int min = 100001;
		cin >> n;

		for (int i = 0; i <n; i++) {
			int x;
			int y;
			cin >> x >> y;
			a.push_back(make_pair(x, y));
		}

		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if (min > a[i].second) {
				min = a[i].second;
				result++;
			}
		}
		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++)cout << answer[i] << endl;
	return 0;

}