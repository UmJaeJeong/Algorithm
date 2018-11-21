#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;

template <typename K>
void print_multiset(multiset<K>& s) {
	//셋의 모든 원소 출력
	for(auto itr = s.begin();itr!=s.end();itr++){
		cout << *itr << endl;
	}
}

template <typename K, typename V>
void print_multimap(multimap<K, V>& m) {
	for (typename multimap<K,V>::iterator itr = m.begin(); itr != m.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}
}

void main() {

	//멀티셋 사용 
	/*
	셋과 멀티셋의 차이 : 중복된 원소를 허락함으로 insert할수 있다.
	*/
	multiset<string> s;

	s.insert("a");
	s.insert("b");
	s.insert("a");
	s.insert("d");
	s.insert("c");

	print_multiset(s);

	//멀티맵 사용
	// 한키에 여러 값(value)를 넣을 수있다.
	multimap<int, string> m;
	m.insert(make_pair(1, "hellow"));
	m.insert(make_pair(1, "hi"));
	m.insert(make_pair(1, "ahihi"));
	m.insert(make_pair(2, "bye"));
	m.insert(make_pair(2, "baba"));

	print_multimap(m);

	//중복된것들 중에 나오는것?
	cout << "----------------------------" << endl;
	cout << m.find(1)->second << endl;
	//라이브러리 경우마다 다르기 때문에 무엇이 나올지는 모른다.
	//C++여기와 같은경우는 맨처음에 insert한 값이 나오지만 바뀔수도 있다.

	//멀티맵 경우에 []연산자를 사용할 수없다.

	cout << "----------------------------" << endl;

	//---키값에 대응되는 값(value)들이 무엇이 있는지 아는 방법---
	auto range = m.equal_range(1);//equal_range()함수를 이용하여 키가 1인 값들을 찾음(multimap에서만 가능)
	for (multimap<int,string>::iterator itr = range.first; itr != range.second; itr++) {
		cout << itr->first << " : " << itr->second << " " << endl;
	}

}
