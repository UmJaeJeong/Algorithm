#include<iostream>
#include<string>
using namespace std;


template <typename T> //template 프로그래머가 원하는 타입으로 변환
/*
벡터>> 
쉽게 생각하면 가변 길이 배열로 사용자가 배열처럼 사용함
크기를 마음대로 줄이고 늘릴수있는 편한 자료형
*/

/*
스택>>
나중에 들어간 것이 먼저나온다.(LIFO-last in first out)형태 자료형
push와 pop으로 작업 처리 가능
*/

class Vector {
	//Vector의 자료형을 string형으로 선언한다고 예를 듬
	T* data;
	int capacity;
	int length;

public :
	//생성자
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {
	}

	//맨 뒤에 새로운 원소를 추가한다.
	void push_back(T s) {
		//capacity(메모리할당량)이 length(길이)보다 작거나 같은 경우 
		if (capacity <= length) {
			T* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}

			//기존의 할당된 메모리를 삭제(할당메모리가 달라졌기에 기존에 있는 메모리를삭제)
			delete[] data;
			data = temp;
			capacity *= 2;
		}
	}

	//operator => 우선순위를 알려줌
	//임의의 위치에 원소에 접근한다.
	T operator[](int i) { return data[i]; }

	//x번째 위치한 원소를 제거
	void remove(int x) {
		//앞으로 한칸씩 당겨 없앰
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	//현재 벡터의 크기를 구한다.
	int size() { return length; }

	//소멸자
	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};

//첫번째 만들때 template를 사용하지 않고 string을 사용
//위와 같이 실행하면 string타입의 데이터 밖에 저장 불가능
//int나 char를 담고 싶다면?  template를 사용 


void main() {
	//ex)
	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(2);

	Vector<string> str_vec;
	str_vec.push_back("hellow");
	str_vec.push_back("what?");



}