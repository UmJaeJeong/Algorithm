#include<iostream>
using namespace std;
//�÷��̵�ͼ� �˰��� 
//�ð� ���⵵ ==> O(N*N*N)
//���ͽ�Ÿ �˰��� ��쿡�� start��� ��, �������� ��� ����� �ִܰ�θ� �˰���
//������, �÷��̵�ͼ� �˰��� ��쿡�� N:N ��, �� �� ���� ��� ���鰣�� �ִܰ�θ� �˷��ִ� �˰���
//���ͽ�Ʈ��� �÷��̵�ͼ� �Ѵ� ���̳������α׷��ֿ� �ǰ��Ѵ�.
int INF = 1000000000;
int number = 4;

//�Էµ� �������� ��� 
int a[4][4] = {
	{ 0, 5, INF, 8 },
{ 7, 0, 9, INF },
{ 2, INF, 0, 4 },
{ INF, INF, 3, 0 }
};

void floydwarshall() {
	int d[4][4];

	//init �ʱ�ȭ
	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			d[i][j] = a[i][j];

	//���İ��� ��� �߽�
	for(int k=0; k<number;k++)
		//������
		for(int i=0; i<number;i++)
			//����
			for (int j = 0; j < number; j++) 
				if (d[i][k] + d[k][j] < d[i][j]) 
					d[i][j] = d[i][k] + d[k][j];

	//���
	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			cout << i+1 << '~' << j+1<<' '<< d[i][j] << endl;
				
}


int main() {
	floydwarshall();
	return 0;
}