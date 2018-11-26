#include<iostream>
using namespace std;
int number = 15;

//����Ʈ�� ������ ��ȸ�˰���
typedef struct node* treenode;
typedef struct node {
	int data;//�ڱ��ڽ� ����� ������
	treenode left, right; // ���� �ڽİ� ������ �ڽ� NULL ���̸� �����̳� �����ʿ� �ڽľ��ٰ� �Ǻ� ����
}node;


//������ȸ
//�ڱ��ڽ� -> �����ڽ� -> ������ �ڽ�
void preorder(treenode ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		//����Լ��� �ҷ��ͼ� ���
		preorder(ptr->left);//���� �ڽİ˻�
		preorder(ptr->right);//������ �ڽİ˻�
	}
}


//������ȸ
//�����ڽ� -> �ڱ��ڽ� -> ������ �ڽ�
void inorder(treenode ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data << ' ';
		inorder(ptr->right);
	}
}

//������ȸ=> ������ȸ�� ������� ��ǻ�ͷ� ���� ���鶧 ���� ����Ѵ�. 
//root�� �����ڸ� �ְ� left�� right�� ���� �־� ���
//�����ڽ� -> �������ڽ� -> �ڱ��ڽ�
void postorder(treenode ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << ' ';
	}
}


int main() {
	node nodes[16];
	
	//�� ��� ����  ���� �ڽ��� ����
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}

	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) {//���� �ڽ� �Է�
			nodes[i / 2].left = &nodes[i];
		}
		else {//������ �ڽ� �Է�
			nodes[i / 2].right = &nodes[i];
		}
	}

	cout << "������ȸ" << endl;
	preorder(&nodes[1]);
	cout << endl;
	cout << "������ȸ" << endl;
	inorder(&nodes[1]);
	cout << endl;
	cout << "������ȸ" << endl;
	postorder(&nodes[1]);



	return 0;
}