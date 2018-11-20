#include<iostream>
#include<string>
using namespace std;


template <typename T> //template ���α׷��Ӱ� ���ϴ� Ÿ������ ��ȯ
/*
����>> 
���� �����ϸ� ���� ���� �迭�� ����ڰ� �迭ó�� �����
ũ�⸦ ������� ���̰� �ø����ִ� ���� �ڷ���
*/

/*
����>>
���߿� �� ���� �������´�.(LIFO-last in first out)���� �ڷ���
push�� pop���� �۾� ó�� ����
*/

class Vector {
	//Vector�� �ڷ����� string������ �����Ѵٰ� ���� ��
	T* data;
	int capacity;
	int length;

public :
	//������
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {
	}

	//�� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
	void push_back(T s) {
		//capacity(�޸��Ҵ緮)�� length(����)���� �۰ų� ���� ��� 
		if (capacity <= length) {
			T* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}

			//������ �Ҵ�� �޸𸮸� ����(�Ҵ�޸𸮰� �޶����⿡ ������ �ִ� �޸𸮸�����)
			delete[] data;
			data = temp;
			capacity *= 2;
		}
	}

	//operator => �켱������ �˷���
	//������ ��ġ�� ���ҿ� �����Ѵ�.
	T operator[](int i) { return data[i]; }

	//x��° ��ġ�� ���Ҹ� ����
	void remove(int x) {
		//������ ��ĭ�� ��� ����
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	//���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length; }

	//�Ҹ���
	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};

//ù��° ���鶧 template�� ������� �ʰ� string�� ���
//���� ���� �����ϸ� stringŸ���� ������ �ۿ� ���� �Ұ���
//int�� char�� ��� �ʹٸ�?  template�� ��� 


void main() {
	//ex)
	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(2);

	Vector<string> str_vec;
	str_vec.push_back("hellow");
	str_vec.push_back("what?");



}