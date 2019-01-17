#include<iostream>
using namespace std;
//������ȹ�� -> ����Ž������ Ȱ��
//BFSȰ��
//-1�� �����ϸ� ���� ������ ���9�� �̻��� ��쿡�� ����
//�Էµ��� �ʾ� -1�� ��µȴ�.
int answer = -1;


void bfs(int N, int number, int sum, int cnt) {
	//�ִ밡 8�̹Ƿ� 9�̻��ϰ�� ����
	if (cnt > 8) return;
	//number�� ������ ������� 
	if (sum == number) {
		//�켱 cnt�� ���� �Էµ� answer���� ���Ͽ� �ּҰ����� Ȯ��
		//ó�� if���� �����°�� answer�� �ռ����ǰ� �����ʾ�
		//or�������� ó���� ���� -1�� ��쿡�� �����ϰ� ���ش�.
		if (cnt < answer || answer == -1) {
			answer = cnt;
		}
		return;
	}

	//��ó���� �Էµɰ��� N����? NN����? NNN����?
	//�ִ� N�� ���Ƚ���� 8���� �̹Ƿ� ���ǹ� �ϼ�
	//ar�� N�� ���ڸ� ����Ѵٴ� ������ ������ *�� ��
	int ar = 0;
	for (int i = 0; i < 8; i++) {
		ar = ar * 10 + N;// i=0 -> N, i=1 -> NN, i=2 -> NNN .....

		//cnt+1+i�� i�� 0���� ���۵ǹǷ� ar�� N�ϰ�쿡�� +1�� ���ֱ����� ���
		bfs(N, number, sum + ar, cnt + 1 + i);
		bfs(N, number, sum - ar, cnt + 1 + i);
		bfs(N, number, sum / ar, cnt + 1 + i);
		bfs(N, number, sum * ar, cnt + 1 + i);
	}
}


int solution(int N, int number) {
	bfs(N, number, 0, 0);
	return answer;
}

int main() {
	int N = 5;
	int number = 12;
	cout << solution(N, number);
	return 0;
}