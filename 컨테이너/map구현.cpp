#include<iostream>
#include<map>
#include<string>

using namespace std;

/*���� �°� ���� �Ȱ��� ����
   ���� Ű�� ����
   ���� ��� Ű�� �����Ǵ� ��(value)�� ���� ����
   */

template <typename K, typename V>
void print_map(map<K,V>& m) {
	//���� ��� ���ҵ��� ���
	for (typename map<K,V>::iterator itr = m.begin(); itr != m.end(); itr++) {
		cout<<itr->first<<" "<<itr
	}
}
void main() {

}