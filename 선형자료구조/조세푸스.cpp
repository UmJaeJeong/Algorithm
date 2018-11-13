#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
/*
문제 : 조세푸스
1세기에 살던 역사학자 조세푸스는 로마와의 전쟁에서 패해 N - 1명의 동료 병사들과 함께 출구가 없는 동굴에 포위당했다고 합니다.
동료 병사들은 로마에 항복하느니 차라리 자살하자고 결의했고, 포위당한 N명의 사람들이 모두 원형으로 둘러선 뒤 순서대로 자살하기로 했습니다.
한 사람이 자살하면, 다음에는 그 사람으로부터 시계 방향으로 K번째 살아 있는 사람이 자살하는 것입니다.
조세푸스의 책에 따르면 조세푸스와 다른 병사 하나만이 살아남았을 때 이들은 마음을 바꿔 로마에 항복해서 살아남았다고 합니다.
마지막 두 명 중 하나가 되기 위해서는 조세푸스는 첫 번째 병사로부터 몇 자리 떨어진 곳에 있어야 했을까요?

<입력>
입력의 첫 번째 줄에는 테스트 케이스의 개수 C (C≤50)가 주어집니다. 각 테스트 케이스는 두 개의 정수 N, K로 주어집니다(3≤N≤1000, 1≤K≤1000).

<출력>
각 테스트 케이스에 두 개의 정수로, 마지막 살아남는 두 사람의 번호를 오름차순으로 출력합니다.
첫 번째로 자살하는 병사의 번호가 1이며, 다른 사람들의 번호는 첫 번째 병사에서부터 시계 방향으로 정해집니다.
*/
void solution(int N, int K) {
	list<int> Human;//생존자


	//생존자 입력
	for (int i = 1; i <= N; i++) {
		Human.push_back(i);
	}

	//죽은사람을 나타내는 반복자
	list<int>::iterator kill;
	kill = Human.begin();
	while (N > 2) {
		//첫번재 사람이 자살한다. erase()는 지운 원소의 다음 원소를 반환한다.
		kill = Human.erase(kill);
		//마지막이 아닌걸 죽일때는 다음원소가 반환되지만
		//마지막을 죽였을때는 다음값은 전체사이즈다
		//따라서 kill이 마지막을 가르키면 처음값으로 돌려놔야 원형 리스트로 동장가능
		if (kill == Human.end()) kill = Human.begin();
		N--;

		for (int i = 0; i < K - 1; i++) { //erase할 경우 다음원소를 가지고 있기때문에 K-1번만한다.
			kill++;
			

			if (kill == Human.end()) {
				kill = Human.begin();
			}
		}
	}
	cout << Human.front() << " " << Human.back() << endl;
}


void main() {
	int C = 0;//테스트 케이스
	int N = 0;// 인원수
	int K = 0;// K번쨰 사람 죽이기

	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> K;
		solution(N, K);
	}
}
