//1차원에서의 BFS

#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n, k;
	//n은 수빈이 위치
	//k는 동생의 위치
	cin >> n >> k;
	int visit[100002] = { 0 };
	
	int dis[100002] = { 0 };
	int dx[2] = { -1,1 };
	queue<int>Q;

	Q.push(n); //일단 수빈이 위치 넣고 시작
	visit[n] = 1; //방문 체크

	//visit[k] = -1; //동생의 위치는 -1로! -> 이게 단순히 방문 여부를 보고 있는 거라 의미가 없음.

	//그냥 위치 기준으로 생각하는게 더 편하다!
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == k) {
			cout << dis[cur];
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			int nx = cur + dx[i];
			if (nx < 0 || nx > 100000) continue;
			if (visit[nx]) continue;
			
			Q.push(nx);
			visit[nx] = 1;
			dis[nx] = dis[cur] + 1;

		}

		if ( 2 * cur <= 100000 && !visit[2 * cur] ) {
			Q.push(2 * cur);
			visit[2 * cur] = 1;
			dis[2 * cur] = dis[cur] + 1;
		
		}
	}



}