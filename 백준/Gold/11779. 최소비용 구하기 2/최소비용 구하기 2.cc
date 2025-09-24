#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;
int n, m; //정점 개수, 간선 개수
vector<pair<int, int>> adj[1005];
int d[1005]; //최단 거리 배열
int pre_city[1005]; //어디서 왔는지 경로 저장
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	//출발 도시, 다음 도시, 비용
	fill(d, d + n + 1, INF);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		//비용, 도착 도시
		adj[u].push_back({ w,v });
	}
	//출발 도시/ 도착 도시
	int st, ed;
	cin >> st >> ed;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	d[st] = 0;
	pre_city[st] = 0;
	//비용, 도시
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (d[cur.Y] != cur.X) continue; //갱신됐는데 확인할 필요 없음
		for (auto nxt : adj[cur.Y]) { //다음 정점 다 꺼내오기
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; //최단 거리에 갱신한 거보다 큰데 넣을 필요 없음
			d[nxt.Y] = d[cur.Y] + nxt.X; //최단거리 갱신
			pre_city[nxt.Y] = cur.Y; //경로 갱신
			pq.push({ d[nxt.Y],nxt.Y });
		}
	}

	cout << d[ed] << "\n"; //최소 비용 출력
	int idx=ed;
	int cnt = 1;
	vector<int>way;
	way.push_back(ed);
	while (1) {
		cnt++;
		idx = pre_city[idx];
		//cout << "idx::::" << idx << "\n";
		way.push_back(idx);
		if (idx == st) break;
	}
	cout << cnt << "\n";
	reverse(way.begin(), way.end());
	for (auto w : way) cout << w << " ";
}