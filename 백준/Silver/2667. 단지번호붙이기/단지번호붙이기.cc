#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bored[27][27];
bool vis[27][27];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
vector<int>vec;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			bored[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, int>>Q;
	int cnt = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (vis[r][c] || bored[r][c] == 0) continue;
			Q.push({ r,c });
			vis[r][c]=1;
			int area = 0;
			while (!Q.empty()) {
				pair<int, int>cur = Q.front();
				Q.pop();
				area++;
				for (int dis = 0; dis < 4; dis++) {
					int nr = cur.first + dr[dis];
					int nc = cur.second + dc[dis];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
					if (vis[nr][nc] || bored[nr][nc] == 0)continue;
					vis[nr][nc] = 1;
					Q.push({ nr,nc });
				}
			}
			cnt++;
			vec.push_back(area);
		}
	}
	sort(vec.begin(), vec.end());
	cout << cnt << '\n';
	for (int x : vec) cout << x << "\n";



}