#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
하나의 양팔 저울을 이용하여 물건의 무게를 측정하려고 한다.이 저울의 양 팔의 끝에는 물건이나 추를 올려놓는
접시가 달려있고, 양팔의 길이는 같다. 또ㅇ한, 저울의 한쪽에는 저울추들만 놓을수 있고 다른쪽에는
측정하려는 물건만 올려놓을 수 있다.
무게가 양의 정수인 N개의 저울추가 주어질대, 이추들을 사용하여 측정할 수 없는 양의 정수 무게중
최솟값을 구하는 프로그램 작성
*/
int main() {
	int n;
	cin >> n;
	vector<int> a;
	int result = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		if (result < a[i])break;
		result += a[i];
		
	}

	cout << result;
	return 0;
}