#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;

template <typename K>
void print_multiset(multiset<K>& s) {
	//���� ��� ���� ���
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

	//��Ƽ�� ��� 
	/*
	�°� ��Ƽ���� ���� : �ߺ��� ���Ҹ� ��������� insert�Ҽ� �ִ�.
	*/
	multiset<string> s;

	s.insert("a");
	s.insert("b");
	s.insert("a");
	s.insert("d");
	s.insert("c");

	print_multiset(s);

	//��Ƽ�� ���
	// ��Ű�� ���� ��(value)�� ���� ���ִ�.
	multimap<int, string> m;
	m.insert(make_pair(1, "hellow"));
	m.insert(make_pair(1, "hi"));
	m.insert(make_pair(1, "ahihi"));
	m.insert(make_pair(2, "bye"));
	m.insert(make_pair(2, "baba"));

	print_multimap(m);

	//�ߺ��Ȱ͵� �߿� �����°�?
	cout << "----------------------------" << endl;
	cout << m.find(1)->second << endl;
	//���̺귯�� ��츶�� �ٸ��� ������ ������ �������� �𸥴�.
	//C++����� �������� ��ó���� insert�� ���� �������� �ٲ���� �ִ�.

	//��Ƽ�� ��쿡 []�����ڸ� ����� ������.

	cout << "----------------------------" << endl;

	//---Ű���� �����Ǵ� ��(value)���� ������ �ִ��� �ƴ� ���---
	auto range = m.equal_range(1);//equal_range()�Լ��� �̿��Ͽ� Ű�� 1�� ������ ã��(multimap������ ����)
	for (multimap<int,string>::iterator itr = range.first; itr != range.second; itr++) {
		cout << itr->first << " : " << itr->second << " " << endl;
	}

}
