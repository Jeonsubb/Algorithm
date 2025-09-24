#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second
vector<pair<int, int>>adj[1005];
int d[1005]; //출발점으로부터의 각 정점까지의 최단 거리를 담을 배열
int n, m, ed; //도시, 간선, 목적지
int res[1005]; //목적지 왔다갔다 할 때의 누적 최단 거리
const int INF = 0x3f3f3f3f;

void ds(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq,int st) {
	fill(d, d + n + 1, INF);
	d[st] = 0;
	pq.push({ d[st],st });

	//시작점에서 출발하여 각 정점으로의 최단 거리를 뽑음
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (d[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y],nxt.Y });
		}
	}
	//목적지에서 각 정점까지의 거리는 누적합에 다 더해줘야 됨
	if (st == ed) {
		for (int i = 1; i <= n; i++) res[i] += d[i];
	}
	// 출발지에서 목적지까지의 거리는 걔만 누적합에 더해주면 됨
	else res[st] += d[ed];

}

int main() {
	fill(res, res + n + 1, 0);

	cin >> n >> m >> ed;
	
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	for (int i = 1; i <= n; i++) {
		ds(pq, i);
	}

	cout << *max_element(res, res + n + 1);

}