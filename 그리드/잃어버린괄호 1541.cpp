#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
#define MAX 50	
string answer;
vector<int> index;
//최솟값을 정하는것 

int main(){
	cin >> answer;
	int result = 0;
	string temp = "";
	bool minus = false;
	//끝에도 더해줘야 되기떄문에 null값이 오는 \0에서 값을 더해준다.
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