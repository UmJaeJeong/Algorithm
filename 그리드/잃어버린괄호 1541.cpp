#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define MAX 50	
string answer;
vector<int> index;
//�ּڰ��� ���ϴ°� 

int main(){
	cin >> answer;
	int result = 0;
	string temp = "";
	bool minus = false;
	//������ ������� �Ǳ⋚���� null���� ���� \0���� ���� �����ش�.
	for (int i = 0; i <=answer.size(); i++) {
		if (answer[i] == '+' || answer[i] == '-' || answer[i] == '\0') {
			if (minus) {
				result += -stoi(temp);
			}
			else {
				result += stoi(temp);
			}

			temp = "";
			if (answer[i] == '-') minus = true;
			continue;
		}
		temp += answer[i];
	}

	cout << result << endl;
	return 0;

}