#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/* �ܾ����� 1181����
����: 
���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷� �ۼ�

�Է� : 
ù° �ٿ� �ܾ��� ���� N�� �־�����. 
(1��N��20,000) ��° �ٺ��� N���� �ٿ� ���� 
���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. 
�־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

*/
int number;
string a[20001];

bool compare(string a, string b) {
	if (a.length() < b.length()) return 1;
	else if (a.length()>b.length()) return  0;
	else return a < b;
}

int main(void) {
	
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> a[i];
	}
	
	sort(a, a + number,compare);
	for (int i = 0; i < number; i++) {
		if(a[i]!=a[i+1])
		cout << a[i] << endl;
	}
	return 0;
}