#include<iostream>
using namespace std;
/*1학년은 노는 게 남는 거란 선배의 말을 철석같이 믿고, 전공 과목은 다 수강철회하고 교양 과목은
다 F 받는 방탕한  1학년을 보냈던 태우는 이제 와서 자신의 행동을 후회하고 있습니다.
졸업 전에 채워야 할 학점이 너무 많기 때문입니다.
졸업 필수 학점을 채우려면 전공 과목 N개 중 K개 이상을 수강해야 합니다. 그런데
각 과목은 해당 과목의 선수과목을 미리 수강했어야만 수강할 수 있으며,
각 학기마다 모든 과목이 개설되는 것이 아니기 때문에 문제가 복잡해졌습니다.
어떻게 해야 최소 학기에 졸업을 할 수 있을까요?*/

/*각 과목의 정보와 앞으로 M학기 동안 개설될 과목의 목록이 주어질 때, 태우가 최소 몇 학기를
다녀야 졸업할 수 있는지 계산하는 프로그램을 작성
한과목도 수강하지 않은 학기는 휴학한 것으로 하며, 다닌 학기 수에 포함되지 않는다.*/

//과목 종류 N개
//K개이상 수강해야함

/*입력의 첫 줄에는 테스트 케이스의 수 C(C<=50)가 주어집니다. 각 테스트 케이스의
첫 줄에는 전공 과목의 수 N(1<=N<=12)
들어야 할 과목의 수 K(0<=K<=N)
학기의 수 M(1<=M<=10)과
태우가 한 학기에 최대로 들을 수 있는 과목의 수 L(1<=L<=10)이 주어짐
각 과목에ㅐ는 0부터 ~ N-1까지의 번호가 있음
*/

const int MAX = 12; //majorNum<=12

const int INF = 987654321;



int majorNum, required; //전공 수, 전공필수

int semesterNum, semesterMax; //학기 수, 한 학기 최대



//prerequiiste[i] = i번째 과목의 선수과목의 집합

int prerequisite[MAX];

//classes[i] = i번째 학기에 개설되는 과목의 집합

int classes[10];

int cache[10][1 << MAX];


int graduate(int semester, int taken) {
	return 0;
}

int main(void)
{


	int test_case;
	cin >> test_case;

	if (test_case < 1 || test_case>50)
		exit(-1);

	for (int j = 0; j < test_case; j++)
	{
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(classes, 0, sizeof(classes));
		memset(cache, -1, sizeof(cache));
		cin >> majorNum >> required >> semesterNum >> semesterMax;



		for (int j = 0; j < majorNum; j++)
		{
			int preNum; //선수 과목 수
			cin >> preNum;

			for (int k = 0; k < preNum; k++)
			{
				int subject; //과목 입력
				cin >> subject;
				prerequisite[j] |= (1 << subject);
			}
		}



		for (int j = 0; j < semesterNum; j++)
		{
			int classNum; //학기에 열린 강의 갯수
			cin >> classNum;

			for (int k = 0; k < classNum; k++)
			{
				int subject; //과목 입력
				cin >> subject;

				classes[j] |= (1 << subject);
			}
		}



		int result = graduate(0, 0);

		if (result == INF)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result << endl;
	}
	return 0;

}