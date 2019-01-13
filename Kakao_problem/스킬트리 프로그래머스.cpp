#include<string>
#include<vector>
#include<iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		vector<char> compare;
		//�ߺ� �ݺ� => skill�� skill_trees[i]�� ���Ͽ� 
		//���Ե� ���� �����ϸ� compare push_back(�Է�)
		for (int k = 0; k < skill_trees[i].size(); k++) {
			for (int j = 0; j < skill.size(); j++) {
				if (skill[j] == skill_trees[i][k]) {
					char tmp = skill[j];
					compare.push_back(tmp);
				}
			}
		}
		bool check = true;;
		//compare�� �Էµ� ���� ������ skill�� ������ �����ϴٸ�
		//answer�� 1�� �߰� �������� �ʴٸ� ����
		for (int c = 0; c < compare.size(); c++) {
			if (skill[c] != compare[c]) {
				check = false;
			}
		}
		if (check)answer++;
	}

	return answer;
}


int main() {
	string skill = "CBD";
	vector<string> skill_trees;
	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");

	cout<<solution(skill, skill_trees);



	return 0;
}