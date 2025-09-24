#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define X first
#define Y second

int v, e, st;

//비용, 정점 번호
vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; //최단 거리 테이블
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v }); //벡터의 배열이니깐 여러개가 들어가는 거네
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	d[st] = 0;
	//우선순위 큐에 (0,시작점) 추가
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top(); //우선순위 큐니까 제일 작은 놈
		pq.pop(); //날리고
		if (d[cur.Y] != cur.X) continue; //확정 거리랑 제일 작은 놈이 들고 있는 비용이랑 다르면 날림
		for (auto nxt : adj[cur.Y]) { //해당 정점과 연결된 모든 비용, 정점 
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; //갱신한거랑 원래거랑 비교해서 크면 갱신을 날림
			d[nxt.Y] = d[cur.Y] + nxt.X; //갱신 된거니까 갱신해줌
			pq.push({ d[nxt.Y],nxt.Y }); //우선순위 큐 갱신
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF)cout << "INF\n";
		else cout << d[i] << "\n";
	}

}







