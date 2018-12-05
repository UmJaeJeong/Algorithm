#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//라빈카프 알고리즘 ==> 항상 빠르지는 않지만 일반적인 경우
//						빠르게 작동하는 간단한 구조의 문자열 매칭 알고리즘
//						문자열의 해쉬값을 비교하여 같은 값인지 비교하는 알고리즘 

/*
특징:
해시기법을 사용 즉,일반적으로 긴 데이터를 그것을 상징하는 짧은 데이터로 바꾸어주는 기법
단순할 경우  시간복잡도가 O(1)일에 가가깝다.

해쉬값 충돌이 있는 경우도 있지만 매우 적다
만약, 충돌이 일어나는 경우 포인터를 이용하여 연결자료구조로 해결할수 있다.
*/

void findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;

	for (int i = 0; i <= parentSize - patternSize; i++) {
		//0일경우 맨처음에만 
		if (i == 0) {
			//pattern의 해쉬값과 stirng의 앞부분 해쉬값을 저장
			for (int j = 0; j < patternSize; j++) {
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power *= 2;
			}
		}
		//parent의 string을 앞부분은 빼고 뒷부분은 1씩 추가하면서 확인
		else {
			//앞에 곱하기2하는 이유는 앞의 값을 빼었고 새로들어온 수가 2의0승 자리를 차지하므로
			//나머지를 모두 1승씩 올려줘야 된다.
			//긴글 해쉬값 = 2*(기존 해시값 - 가장앞에 있는 문자수식)+새롭게 들어온 문자 수식
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}
		if (parentHash == patternHash) {
			bool finded = true;
			//문자열이 같은지 하나씩 다 비교
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
				}
			}
			if (finded) {
				cout << i + 1 << "번째에서 발견" << endl;
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