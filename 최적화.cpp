#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Dictionary
{
	//해당 키를 갖는 항목이 있는지 여부를 반환한다.
	bool has(const string& key);
	//해당 키와 값을 갖는 항목을 추가한다.
	void insert(const string& key, const string& value);
	//해당 키를 갖는 항목의 값을 얻는다.
	string get(const string& key);
	//해당 키를 갖는 항목을 삭제한다.
	void erase(const string& key);
};


struct Dictionary {
	//keys[i]와 values[i]는 i번재 항목의 키와 값을 나타낸다.
	vector<string> keys, values;
	/****************************/
	bool has(const string& key);
	void insert(const string& key, const string& value);
	void erase(const string& key);


};

bool Dictionary::has(const string& key) {
	//keys 벡터에 key가 존재하는지 여부를 반환
	return find(keys.begin(), keys.end(), key) != keys.end();
}
void Dictionary::insert(const string& key, const string& value) {
	//해당 키를 갖는 항목이 이미 존재할 경우 지운다.
	if (has(key)) erase(key);
	//키와 값을 추가
	keys.push_back(key);
	values.push_back(value);
}

//위와같이 많은양의 새키를 추가하기위해서는 기존에 키가 있는지 없는지 판단을 매번해야되기 때문에
//키와 값의 개수가 늘어날수록 선형적으로 속도가 느려지게 된다.
//이와 같은 작업을 더 빠르게 하기 위해 이진 검색트리를 사용
//위와 같은 

void main() {}