//어떤한 문자열을 검색했을때 특정한 특정만 문자열을 찾는  것
//문자열 매칭 알고리즘  KMP알고리즘, 단순비교 문자열 매칭 알고리즘
//단순비교 문자열 매칭 ==> 한개씩 비교하여함
//KMP ==> 
#include<iostream>
using namespace std;


int findString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();

	for (int i = 0; i < parentSize - patternSize; i++) {
		bool finded = true;
		for (int j = 0; j < patternSize; j++) {
			if (parent[i + j] != pattern[j]) {
				finded = false;
				break;
			}
		}
		if (finded) return i;
	}
	return -1;
	
}

int main(void) {
	string parent = "Hello World";
	string pattern = "llo W";
	int result = findString(parent, pattern);
	if (result == -1) {
		cout << "찾을수 없다" << endl;
	}
	else {
		cout << result + 1 << "번쨰에서 찾았습니다." << endl;
	}

}