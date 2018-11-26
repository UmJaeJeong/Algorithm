#include<stdio.h>

//�θ� ��� ã��
int getParent(int Parent[], int x) {
	//�ڱ��ڽ��� �θ����� ���
	if (Parent[x] == x) return x;
	//����Լ��� �̿��Ͽ� ���������� ã��
	return Parent[x] = getParent(Parent, Parent[x]);
}

//�� ��� or �� �׷����� ������ �ϱ�
int unionParent(int Parent[], int a, int b) {
	//�� �θ����� ��ȣ�� ã��
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	//��� ��ȣ�� ���������� ������ �ϴ°��� �Ϲ���
	if (a > b) return Parent[a] = b;
	return Parent[b] = a;
}

//�� ��尡 ����Ǿ� �ִ��� �ƴ��� �Ǻ�  �Ǻ��� 
//���� ������� �������̶�� �������� ���� ���� ������
int findParent(int Parent[], int a, int b) {
	a = getParent(Parent, a);
	b = getParent(Parent, b);
	//�� ��尡 ����Ǿ� �ִ°�� true
	if (a == b)return 1;
	//�γ�尡 ����Ǿ� ���� ���� ��� false
	return 0;
}


int main() {
	int parent[11];
	//�ϳ��� ������� �ʰ� ���������� �����ϴ� ��� 
	//�� �ڱ��ڽ��� �θ�����
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	printf("1�� 5�� ����Ǿ��ֳ���? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1�� 5�� ����Ǿ��ֳ���? %d\n", findParent(parent, 1, 5));

	return 0;
}