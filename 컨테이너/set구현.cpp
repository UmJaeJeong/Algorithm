#include<iostream>
#include<set>
#include<string>
//연관 컨테이너 키-값 구조를 가짐 
/*
<set, multiset>
1. 박명순이 데이터에 존재하나요?(특정 키가 연관 컨테이너에 존재하는지 유뮤 )-> TRUE
(키의 존재 유무만 확인할 경우 set을 사용하는것이 좋음)
------------------------------------------------------------
<map, multimap>
2. 만약 존재한다면 이에 대응되는 값이 무엇인가요?(특정 키에 대응되는 값이 무엇인지 질의) ->46
(대응되는 값을 원할시에는 map을 사용하는 것이 좋음)
*/
using namespace std;

template <typename T>

void print_set(set<T>& s) {
	//셋의 모든 원소들을 출력하기
	cout << "[";
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); itr++) {
		cout << *itr << " ";
	}
	cout << "]" << endl;
}

class Todo {
	int prioriry; //중요도 . 높을 수록 급한것!
	string job_desc;
public:
	//생성자
	Todo(int priority, string job_desc): prioriry(priority), job_desc(job_desc) {}

	//원소를 출력하기 위한 비교
	bool operator<(const Todo& t) const {
		//우선순위 같을경우
		if (prioriry == t.prioriry) {
			return job_desc < t.job_desc;
		}
		return prioriry > t.prioriry;
	}

	friend ostream& operator<<(ostream& o, const Todo& td);
};

ostream& operator<<(ostream& o, const Todo& td) {
	o << "[ 중요도: " << td.prioriry << "]" << td.job_desc;
	return o;
}


void main() {
	//클래스 객체를 셋에 넣어 사용
	//operator<를 만들어줘야함
	set<Todo> todos;

	todos.insert(Todo(1, "농구하기"));
	todos.insert(Todo(2, "수학 숙제하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화보기"));
	print_set(todos);
	cout << endl;
	cout << endl;



	set<int> s;
	//원소 추가 insert
	s.insert(10);
	s.insert(50);
	s.insert(30);
	s.insert(20);
	s.insert(40);
	//set은 큰상자안에 원소를 정렬하여 순서대로 넣는다고 생각하면 됨
	//원소가 어디있는지가 아닌 상자안에 원소가 있냐 없냐 유무를 앎
	//연관 컨테이너 원소를 추가 및 삭제 시간 O(logN)걸림
	//시퀀스 컨테이너 추가 및 삭제 시간 O(N)걸림

	//컨테이너의 리스트 처럼 임의의  위치에 있는 원소는 접근 불가능!
	//순차적으로 하나씩 접근
	cout << "순서대로 정렬되서 나옴" << endl;
	print_set(s);

	//만약 원소가 존재하지 않으면 find()함수는 end()를 리턴함
	cout << "20이 s의 원소?";
	auto itr = s.find(20);
	if (itr != s.end()) {
		cout << "OK" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	//원소의 값이 같은것은 insert되지 않음
	//중복된 원소를 삽입하고 싶으면 multiset을 사용
	s.insert(10);
	s.insert(10);
	s.insert(50);
	s.insert(50);

	print_set(s);
}