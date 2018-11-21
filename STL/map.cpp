#include<iostream>
#include<map>
#include<string>

using namespace std;

/*���� �°� ���� �Ȱ��� ����
   ���� Ű�� ����
   ���� ��� Ű�� �����Ǵ� ��(value)�� ���� ����
   */

template <typename K, typename V>
void print_map(map<K, V>& m) {
	//���� ��� ���ҵ��� ���
	for (typename map<K, V>::iterator itr = m.begin(); itr != m.end(); itr++) {
		//map�� ���� pair��ü�� ���� ���� �� �����Ƿ� first�� second�� ���
		cout << itr->first << " " << itr->second << endl;
	}
}

template <typename K, typename V>
void search_and_print(map<K, V>& m, K key) {
	typename map<K, V>::iterator itr = m.find(key);
	if (itr != m.end()) {
		cout << key << "--->" <<itr->second<< endl;

	}
	else {//itr == m.end()�� ���  Ű�� �������� ������ end()�� ����  �߿�!!!!!
		cout << key << "��(��) ��Ͽ� �����ϴ�." << endl;
	}
}

void main() {

	//TMI�� �ؿ� �Էµ� ������ 2017�� 7��4�� ������ ��������� ����
	//ù���� ���ڴ� Ű�� Ÿ�� �ι�°�� ���� Ÿ��
	map<string, double> pitcher_list;

	//���� ���Ҹ� �ֱ� ���ؼ� pair��ü�� �����ؾ���
	//���� insert �Լ��� pair ��ü�� ���ڷ� �޽��ϴ�.
	pitcher_list.insert(pair<string, double>("�ڼ���", 2.23));
	pitcher_list.insert(pair<string, double>("��Ŀ", 2.93));

	pitcher_list.insert(pair<string, double>("�Ǿ���:", 2.95));

	//Ÿ���� �������� �ʾƵ� ������ make_pair �Լ���
	//pair ��ü�� ������� �ִ�.
	pitcher_list.insert(make_pair("������", 3.04));
	pitcher_list.insert(make_pair("�����", 3.05));
	pitcher_list.insert(make_pair("����", 3.09));

	//Ȥ�� insert�� �Ⱦ��� []�� �ٷ� ���� �߰� ����
	//operator[]�� �̿��Ͽ� ���� �߰� ����
	pitcher_list["����Ʈ"] = 3.56;
	pitcher_list["������"] = 3.76;
	pitcher_list["�̸�"] = 3.90;

	print_map(pitcher_list);

	//[]�����ڸ� ����� �����ϰ� Ű���� ���� ���� ������ ����
	cout << "�ڼ��� �������? ::" << pitcher_list["�ڼ���"] << endl;

	/*[]������ ��� ������*/
	/*
	Ű���� ��� ���� ã���� ex)picher_list["������"]���� ����Ʈ ������ ��� 0���� �ʱ�ȭ��
	�׷��Ƿ� find�Լ��� �̿��� Ű�� �����ϴ��� Ȯ���� �����ϰ� ���� ã�°��� ����
	*/

	cout << "---------------------------------------" << endl;
	cout << "-----------search_and_print----------" << endl;
	search_and_print(pitcher_list, string("����ȯ"));
	search_and_print(pitcher_lisxt, string("������"));

	//�̹� ���� Ű�� ���ҷ� ��� �ִٸ� ���߿� ���� insert �Է��� ���õ� ���̺κ��� set�� ������
	pitcher_list.insert(make_pair("�ڼ���", 2.23));
	pitcher_list.insert(make_pair("�ڼ���", 2.29));

	//�̹� �ڼ����̶�� Ű�� 2.34�̶�� ���� �ԷµǾ��� ������
	//�ؿ� �ڼ��� 2.29��� value(��)�� �Էµ��� �ʰ� ���õȴ�.
	cout << endl;
	cout << "�ڼ��� �����??  " << pitcher_list["�ڼ���"] << endl;
	}