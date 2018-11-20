#include<iostream>
#include<map>
#include<string>

using namespace std;

/*맵은 셋과 거의 똑같은 구조
   셋은 키만 보관
   맵의 경우 키에 대응되는 값(value)와 같이 보관
   */

template <typename K, typename V>
void print_map(map<K, V>& m) {
	//맵의 모든 원소들을 출력
	for (typename map<K, V>::iterator itr = m.begin(); itr != m.end(); itr++) {
		//map의 값을 pair객체를 통해 얻을 수 있으므로 first와 second를 사용
		cout << itr->first << " " << itr->second << endl;
	}
}

template <typename K, typename V>
void search_and_print(map<K, V>& m, K key) {
	typename map<K, V>::iterator itr = m.find(key);
	if (itr != m.end()) {
		cout << key << "--->" <<itr->second<< endl;

	}
	else {//itr == m.end()일 경우  키가 존재하지 않으면 end()를 리턴  중요!!!!!
		cout << key << "은(는) 목록에 없습니다." << endl;
	}
}

void main() {

	//TMI로 밑에 입력된 값들은 2017년 7월4일 내생일 투수방어율 순위
	//첫번쨰 인자는 키의 타입 두번째는 값의 타입
	map<string, double> pitcher_list;

	//맵의 원소를 넣기 위해서 pair객체를 전달해야함
	//맵의 insert 함수는 pair 객체를 인자로 받습니다.
	pitcher_list.insert(pair<string, double>("박세웅", 2.23));
	pitcher_list.insert(pair<string, double>("해커", 2.93));

	pitcher_list.insert(pair<string, double>("피어밴드:", 2.95));

	//타입을 지정하지 않아도 간단히 make_pair 함수로
	//pair 객체를 만들수도 있다.
	pitcher_list.insert(make_pair("차우찬", 3.04));
	pitcher_list.insert(make_pair("장원준", 3.05));
	pitcher_list.insert(make_pair("헥터", 3.09));

	//혹은 insert를 안쓰고 []로 바로 원소 추가 가능
	//operator[]를 이요하여 원소 추가 가능
	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["켈리"] = 3.90;

	print_map(pitcher_list);

	//[]연산자를 사용해 간단하게 키값을 통해 값을 얻을수 있음
	cout << "박세웅 방어율은? ::" << pitcher_list["박세웅"] << endl;

	/*[]연산자 사용 주의점*/
	/*
	키값이 얻는 것을 찾을시 ex)picher_list["엄재정"]값은 디폴트 생성자 경우 0으로 초기화함
	그러므로 find함수를 이용해 키가 존재하는지 확인후 안전하게 값을 찾는것이 좋음
	*/

	cout << "---------------------------------------" << endl;
	cout << "-----------search_and_print----------" << endl;
	search_and_print(pitcher_list, string("오승환"));
	search_and_print(pitcher_lisxt, string("류현진"));

	//이미 같은 키가 원소로 들어 있다면 나중에 오는 insert 입력은 무시됨 이이부분은 set과 동일함
	pitcher_list.insert(make_pair("박세웅", 2.23));
	pitcher_list.insert(make_pair("박세웅", 2.29));

	//이미 박세웅이라는 키와 2.34이라는 값이 입력되었기 떄문에
	//밑에 박세웅 2.29라는 value(값)은 입력되지 않고 무시된다.
	cout << endl;
	cout << "박세웅 방어율??  " << pitcher_list["박세웅"] << endl;
	}