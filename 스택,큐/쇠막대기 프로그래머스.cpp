#include <string>
#include <vector>
#include <stack>
using namespace std;

//"()"가 연달아 나올경우 레이저
//"))"가 연달아 나올경우 쇠막대기의 끝지점 유의

int solution(string arrangement) {
	int answer = 0;
	stack<int> s;
	for (int i = 0; i<arrangement.size(); i++) {
		//"("일 경우 
		if (arrangement.at(i) == '(') {
			s.push(0);//쇠막대기 1개 증가
		}
		else {  //")"경우
			s.pop();//쇠막대기의 끝 or 레이저 이므로 제거
			if (arrangement.at(i - 1) == '(') {//이전에 괄호가 여는 괄호일 경우 레이저
				answer += s.size();   //레이저로 쇠막대기를 자름 쇠막대기 갯수만큼 증가      
			}
			else {//이전에 괄호가 닫는괄호")"일경우
				answer++;//쇠막대기의 마지막 지점 갯수 1개 증가
			}
		}
	}
	return answer;
}