#include<stdio.h>

void main() {
	int size=0; //�迭�� ũ��
	int* Array=0; //���� �迭�� ����Ű�� ������ (int ��ſ� ElementType��� �ٲܼ� ����);
	int capacity = 1;
	int M = 3;

	//�迭 �뷮�� �� á���� ���Ҵ� �޴´�.
	if (size == capacity) {
		int newCapacity = capacity + M;
		int* newArray = new int[newCapacity];
		//������ �ڷḦ �����Ѵ�.
		for (int i = 0; i < size; i++) {
			newArray[i] = Array[i];
			//������ �迭�� �����ϰ�, ���迭�� �ٲ�ġ��
			if (Array) delete[] Array;
			Array = newArray;
			capacity = newCapacity;
		}
		//�迭�� ���� ���Ҹ� �����Ѵ�.
		//Array[size++] = newValue
	}

	//������� ���Ҵ� �ð� O(N + M)
	//C++�̳� C#�ΰ�쿡�� vector�� ArrayList���� ����Ͽ� �����迭�� �����ϰ� ����Ѵ�.
}