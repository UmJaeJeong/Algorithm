#include<iostream>
using namespace std;
// �ð����⵵ ==>O(N*N)����� ���ͽ�Ʈ�� �˰���


//���ͽ�Ʈ�� �ִܰ�θ� ���ϴ� ���� �������α׷����̳� �׸���˰��򿡵� ���� ���ȴ�.
//���̳������α׷��� ���� ���� �������� ���������� �̵��ϴ� ����� �ִܰŸ��� ��� �˱⶧���� ���

//1.��� ��带 ����
//2. ��� ��带 �������� �� ����� �ּҺ���� ����
//3. �湮���� ���� ��� �߿��� ���� ����� ���� ��带 ����
//4. �ش� ��带 ���ļ� Ư���� ���� ���� ��츦 ��� �ּҺ�� ����
//5. �� �������� 3��~4���� �ݺ�

int number = 6;
bool v[6];
int d[6];
int INF = 1000000000;

//��ü�׷�����  �ʱ�ȭ
int a[6][6] = {
	{ 0, 2, 5, 1, INF, INF },
{ 2, 0, 3, 2, INF, INF },
{ 5, 3, 0, 3, 1, 5 },
{ 1, 2, 3, 0, 1, INF },
{ INF, INF, 1, 1, 0, 2 },
{ INF, INF, 5, INF, 2, 0 },
};
//���������� ������ ���� �ִ��� �Ÿ��� ������ �ִ� ����� indexã��
int getSmallIndex() {
	int index = 0;
	int min = INF;
	for (int i = 0; i < number; i++) {
		//�湮���� �ʾҴ� ��� �˻�
		if (!v[i]) {
			//d[i]�� ����Ǿ��ִ� �ִܰŸ��� ���� index ����
			if (d[i] < min) {
				min = d[i];
				index = i;
			}
		}
	}
	return index;
}

void dijckstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];//start��忡�� ���������� �Ÿ� ����
	}
	v[start] = true;
	//start���� end��带 ������ Ƚ�� �ݺ�
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < number; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}


int main() {
	dijckstra(0);
	for (int i = 0; i < number; i++) cout << d[i];
	return 0;
}