#include <iostream>

using namespace std;
//64��Ʈ ��ȣ ���� ������ [0, 15] ������ ���� 16���� ��� �迭�� ����ϱ�
typedef unsigned long long uint64;//��Ī ��� 


//mask�� index ��ġ�� ���� ���� ��ȯ
int get(uint64 mask, int index) {
	return (mask >> (index << 2)) & 15;
}

//mask�� index ��ġ�� value�� �ٲ� ����� ��ȯ
uint64 set(uint64 mask, int index, uint64 value) {
	return mask & ~(15LL << (index << 2)) | (value << (index << 2));
}

void main() {

}