#include <iostream>
#include <queue>
using namespace std;
class CustomerGroup;
//lineA는 모든 사람이 처음에 서는 줄이다. 줄을 선 일행의 정보는 lineA[0]~
//lineA[lineaEntries-1]에 저장되며, lineA[0]이 가장 앞에 선 일행이다. 때문에
//줄에서 한 사람이 나올 때는 뒤에 있는 원소들을 하나씩 앞으로 옮겨야한다.
//lineB는 4인용 자리가 날 때까지 기다리고 있는 일행들의 줄이다. 역시
//lineB[0]~lineB[lineentries-1]까지가 유효한 값이다.
// 한줄에 일행의 수가 1024가 넘을 경우, 단정문 오류(assertion fail)가 발생한다.
int lineAEntries, lineBEnttries;
CustomerGroup lineA[1024], lineB[1024];

//lineA는 모든 사람이 처음에 저장되는 큐이다.
//lineB는 4인용 자리가 나지않아 기다리고 있는 일행들이 저장되는 큐이다.
queue <CustomerGroup> lineA, lineB;

//위의 선언들과 비교 아래의 선언이 더욱 간결하다. STL의 queue를 사용 
void main() {

}