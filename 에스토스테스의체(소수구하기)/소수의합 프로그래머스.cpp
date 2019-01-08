#include <vector>
#include<cmath>
using namespace std;
#define MAX 10000000
int c[MAX];
void Prime(int x) {
	for (int i = 2; i <= sqrt(x); i++)
	{
		for (int j = i + i; j <= x; j += i) {
			if (c[j] == 1)continue;
			if (c[j] == 0)c[j] = 1;
		}
	}
}
long long solution(int N) {
	long long answer = 0;
	Prime(N);

	for (int i = 2; i <= N; i++) {
		if (c[i] == 0) {
			answer += i;
		}
	}
	return answer;
}