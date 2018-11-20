#include<iostream>
#include<map>
#include<string>

using namespace std;

/*맵은 셋과 거의 똑같은 구조
   셋은 키만 보관
   맵의 경우 키에 대응되는 값(value)와 같이 보관
   */

template <typename K, typename V>
void print_map(map<K,V>& m) {
	//맵의 모든 원소들을 출력
	for (typename map<K,V>::iterator itr = m.begin(); itr != m.end(); itr++) {
		cout<<itr->first<<" "<<itr
	}
}
void main() {

}