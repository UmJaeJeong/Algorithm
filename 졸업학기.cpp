#include<iostream>
using namespace std;
/*1�г��� ��� �� ���� �Ŷ� ������ ���� ö������ �ϰ�, ���� ������ �� ����öȸ�ϰ� ���� ������
�� F �޴� ������  1�г��� ���´� �¿�� ���� �ͼ� �ڽ��� �ൿ�� ��ȸ�ϰ� �ֽ��ϴ�.
���� ���� ä���� �� ������ �ʹ� ���� �����Դϴ�.
���� �ʼ� ������ ä����� ���� ���� N�� �� K�� �̻��� �����ؾ� �մϴ�. �׷���
�� ������ �ش� ������ ���������� �̸� �����߾�߸� ������ �� ������,
�� �б⸶�� ��� ������ �����Ǵ� ���� �ƴϱ� ������ ������ �����������ϴ�.
��� �ؾ� �ּ� �б⿡ ������ �� �� �������?*/

/*�� ������ ������ ������ M�б� ���� ������ ������ ����� �־��� ��, �¿찡 �ּ� �� �б⸦
�ٳ�� ������ �� �ִ��� ����ϴ� ���α׷��� �ۼ�
�Ѱ��� �������� ���� �б�� ������ ������ �ϸ�, �ٴ� �б� ���� ���Ե��� �ʴ´�.*/

//���� ���� N��
//K���̻� �����ؾ���

/*�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C<=50)�� �־����ϴ�. �� �׽�Ʈ ���̽���
ù �ٿ��� ���� ������ �� N(1<=N<=12)
���� �� ������ �� K(0<=K<=N)
�б��� �� M(1<=M<=10)��
�¿찡 �� �б⿡ �ִ�� ���� �� �ִ� ������ �� L(1<=L<=10)�� �־���
�� ���񿡤��� 0���� ~ N-1������ ��ȣ�� ����
*/

const int MAX = 12; //majorNum<=12

const int INF = 987654321;



int majorNum, required; //���� ��, �����ʼ�

int semesterNum, semesterMax; //�б� ��, �� �б� �ִ�



//prerequiiste[i] = i��° ������ ���������� ����

int prerequisite[MAX];

//classes[i] = i��° �б⿡ �����Ǵ� ������ ����

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
			int preNum; //���� ���� ��
			cin >> preNum;

			for (int k = 0; k < preNum; k++)
			{
				int subject; //���� �Է�
				cin >> subject;
				prerequisite[j] |= (1 << subject);
			}
		}



		for (int j = 0; j < semesterNum; j++)
		{
			int classNum; //�б⿡ ���� ���� ����
			cin >> classNum;

			for (int k = 0; k < classNum; k++)
			{
				int subject; //���� �Է�
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