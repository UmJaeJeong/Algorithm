#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int sum = 0;

	//진입한 트럭부터 도착하기위한 큐 사용
	queue<int> q;
	for (int i = 0; i<truck_weights.size(); i++) {
		int t_w = truck_weights[i];
		while (true) {
			//다리에 진입한 트럭이 없을경우 진입 
			if (q.empty()) {
				q.push(t_w);
				answer++;
				sum += t_w;
				break;
			}
			else if (q.size() == bridge_length) {//트럭의 대수와 다리길이 같을경우
				sum -= q.front();//1대씩 나감 그다음에 진입할 트럭의 무게도 고려하기위한 방법
				q.pop();
			}
			else {
				if (sum + t_w>weight) {//현재다리위의 트럭과 다음트럭의 무게 합산이 최대무게가 넘을시
					q.push(0);      //공간만을 차지하기 위한 0의 값을 넣음
					answer++;
				}
				else {
					q.push(t_w);    //현재다리위의 트럭무게가 초과무게를 넘지 않았다면 다음트럭 진입
					answer++;
					sum += t_w;
					break;
				}
			}
		}
	}
	//+bridge_length를 해주는 이유 : 마지막의 트럭이 진입 후 나갈떄까지
	//시간을 추가해준다 트럭이 1초에 길이1만큼 움직이므로
	//bridge_length를 더해줌
	return answer + bridge_length;
}