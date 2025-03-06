#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int>adj[1005];
bool vis[1005]; //이걸 초기화 안해도 되는 이유가 연결된 것의 개수니까 그렇네...
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	//정점, 간선 개수
	int n, m;
	cin >> n >> m;
	
	//그래프 인접행렬로
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//BFS... 기억 안난다,,
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		num++;
		queue<int>q;
		q.push(i);
		vis[i] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto nxt : adj[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}

	}
	cout << num;

}