#include <string>
#include <vector>
#include <stack>
using namespace std;

//"()"�� ���޾� ���ð�� ������
//"))"�� ���޾� ���ð�� �踷����� ������ ����

int solution(string arrangement) {
	int answer = 0;
	stack<int> s;
	for (int i = 0; i<arrangement.size(); i++) {
		//"("�� ��� 
		if (arrangement.at(i) == '(') {
			s.push(0);//�踷��� 1�� ����
		}
		else {  //")"���
			s.pop();//�踷����� �� or ������ �̹Ƿ� ����
			if (arrangement.at(i - 1) == '(') {//������ ��ȣ�� ���� ��ȣ�� ��� ������
				answer += s.size();   //�������� �踷��⸦ �ڸ� �踷��� ������ŭ ����      
			}
			else {//������ ��ȣ�� �ݴ°�ȣ")"�ϰ��
				answer++;//�踷����� ������ ���� ���� 1�� ����
			}
		}
	}
	return answer;
}