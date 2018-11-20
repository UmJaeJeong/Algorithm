#include<iostream>
#include<set>
#include<string>
//���� �����̳� Ű-�� ������ ���� 
/*
<set, multiset>
1. �ڸ���� �����Ϳ� �����ϳ���?(Ư�� Ű�� ���� �����̳ʿ� �����ϴ��� ���� )-> TRUE
(Ű�� ���� ������ Ȯ���� ��� set�� ����ϴ°��� ����)
------------------------------------------------------------
<map, multimap>
2. ���� �����Ѵٸ� �̿� �����Ǵ� ���� �����ΰ���?(Ư�� Ű�� �����Ǵ� ���� �������� ����) ->46
(�����Ǵ� ���� ���ҽÿ��� map�� ����ϴ� ���� ����)
*/
using namespace std;

template <typename T>

void print_set(set<T>& s) {
	//���� ��� ���ҵ��� ����ϱ�
	cout << "[";
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); itr++) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
}

class Todo {
	int prioriry; //�߿䵵 . ���� ���� ���Ѱ�!
	string job_desc;
public:
	//������
	Todo(int priority, string job_desc): prioriry(priority), job_desc(job_desc) {}

	//���Ҹ� ����ϱ� ���� ��
	bool operator<(const Todo& t) const {
		//�켱���� �������
		if (prioriry == t.prioriry) {
			return job_desc < t.job_desc;
		}
		return prioriry > t.prioriry;
	}

	friend ostream& operator<<(ostream& o, const Todo& td);
};

ostream& operator<<(ostream& o, const Todo& td) {
	o << "[ �߿䵵: " << td.prioriry << "]" << td.job_desc;
	return o;
}


void main() {
	//Ŭ���� ��ü�� �¿� �־� ���
	//operator<�� ����������
	set<Todo> todos;

	todos.insert(Todo(1, "���ϱ�"));
	todos.insert(Todo(2, "���� �����ϱ�"));
	todos.insert(Todo(1, "���α׷��� ������Ʈ"));
	todos.insert(Todo(3, "ģ�� ������"));
	todos.insert(Todo(2, "��ȭ����"));
	print_set(todos);
	cout << endl;
	cout << endl;



	set<int> s;
	//���� �߰� insert
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	//set�� ū���ھȿ� ���Ҹ� �����Ͽ� ������� �ִ´ٰ� �����ϸ� ��
	//���Ұ� ����ִ����� �ƴ� ���ھȿ� ���Ұ� �ֳ� ���� ������ ��
	//���� �����̳� ���Ҹ� �߰� �� ���� �ð� O(logN)�ɸ�
	//������ �����̳� �߰� �� ���� �ð� O(N)�ɸ�

	//�����̳��� ����Ʈ ó�� ������  ��ġ�� �ִ� ���Ҵ� ���� �Ұ���!
	//���������� �ϳ��� ����
	cout << "������� ���ĵǼ� ����" << endl;
	print_set(s);

	//���� ���Ұ� �������� ������ find()�Լ��� end()�� ������
	cout << "20�� s�� ����?";
	auto itr = s.find(20);
	if (itr != s.end()) {
		cout << "OK" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	//������ ���� �������� insert���� ����
	//�ߺ��� ���Ҹ� �����ϰ� ������ multiset�� ���
	s.insert(10);
	s.insert(10);
	s.insert(50);
	s.insert(50);

	print_set(s);
}