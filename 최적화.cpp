#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Dictionary
{
	//�ش� Ű�� ���� �׸��� �ִ��� ���θ� ��ȯ�Ѵ�.
	bool has(const string& key);
	//�ش� Ű�� ���� ���� �׸��� �߰��Ѵ�.
	void insert(const string& key, const string& value);
	//�ش� Ű�� ���� �׸��� ���� ��´�.
	string get(const string& key);
	//�ش� Ű�� ���� �׸��� �����Ѵ�.
	void erase(const string& key);
};


struct Dictionary {
	//keys[i]�� values[i]�� i���� �׸��� Ű�� ���� ��Ÿ����.
	vector<string> keys, values;
	/****************************/
	bool has(const string& key);
	void insert(const string& key, const string& value);
	void erase(const string& key);


};

bool Dictionary::has(const string& key) {
	//keys ���Ϳ� key�� �����ϴ��� ���θ� ��ȯ
	return find(keys.begin(), keys.end(), key) != keys.end();
}
void Dictionary::insert(const string& key, const string& value) {
	//�ش� Ű�� ���� �׸��� �̹� ������ ��� �����.
	if (has(key)) erase(key);
	//Ű�� ���� �߰�
	keys.push_back(key);
	values.push_back(value);
}

//���Ͱ��� �������� ��Ű�� �߰��ϱ����ؼ��� ������ Ű�� �ִ��� ������ �Ǵ��� �Ź��ؾߵǱ� ������
//Ű�� ���� ������ �þ���� ���������� �ӵ��� �������� �ȴ�.
//�̿� ���� �۾��� �� ������ �ϱ� ���� ���� �˻�Ʈ���� ���
//���� ���� 

void main() {}