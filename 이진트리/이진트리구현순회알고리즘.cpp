#include<iostream>
using namespace std;
int number = 15;

//이진트리 구현과 순회알고리즘
typedef struct node* treenode;
typedef struct node {
	int data;//자기자신 노드의 데이터
	treenode left, right; // 왼쪽 자식과 오른쪽 자식 NULL 값이면 왼쪽이나 오른쪽에 자식없다고 판별 가능
}node;


//전위순회
//자기자신 -> 왼쪽자식 -> 오른쪽 자식
void preorder(treenode ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		//재귀함수를 불러와서 사용
		preorder(ptr->left);//왼쪽 자식검색
		preorder(ptr->right);//오른쪽 자식검색
	}
}


//중위순회
//왼쪽자식 -> 자기자신 -> 오른쪽 자식
void inorder(treenode ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data << ' ';
		inorder(ptr->right);
	}
}

//후위순회=> 후위순회와 같은경우 컴퓨터로 계산기 만들때 많이 사용한다. 
//root에 연산자를 넣고 left와 right에 값을 넣어 사용
//왼쪽자식 -> 오른쪽자식 -> 자기자신
void postorder(treenode ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << ' ';
	}
}


int main() {
	node nodes[16];
	
	//각 노드 구현  아직 자식이 없음
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}

	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) {//왼쪽 자식 입력
			nodes[i / 2].left = &nodes[i];
		}
		else {//오른쪽 자식 입력
			nodes[i / 2].right = &nodes[i];
		}
	}

	cout << "전위순회" << endl;
	preorder(&nodes[1]);
	cout << endl;
	cout << "중위순회" << endl;
	inorder(&nodes[1]);
	cout << endl;
	cout << "후위순회" << endl;
	postorder(&nodes[1]);



	return 0;
}