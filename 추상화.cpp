#include <iostream>
#include <queue>
using namespace std;
class CustomerGroup;
//lineA�� ��� ����� ó���� ���� ���̴�. ���� �� ������ ������ lineA[0]~
//lineA[lineaEntries-1]�� ����Ǹ�, lineA[0]�� ���� �տ� �� �����̴�. ������
//�ٿ��� �� ����� ���� ���� �ڿ� �ִ� ���ҵ��� �ϳ��� ������ �Űܾ��Ѵ�.
//lineB�� 4�ο� �ڸ��� �� ������ ��ٸ��� �ִ� ������� ���̴�. ����
//lineB[0]~lineB[lineentries-1]������ ��ȿ�� ���̴�.
// ���ٿ� ������ ���� 1024�� ���� ���, ������ ����(assertion fail)�� �߻��Ѵ�.
int lineAEntries, lineBEnttries;
CustomerGroup lineA[1024], lineB[1024];

//lineA�� ��� ����� ó���� ����Ǵ� ť�̴�.
//lineB�� 4�ο� �ڸ��� �����ʾ� ��ٸ��� �ִ� ������� ����Ǵ� ť�̴�.
queue <CustomerGroup> lineA, lineB;

//���� ������ �� �Ʒ��� ������ ���� �����ϴ�. STL�� queue�� ��� 
void main() {

}