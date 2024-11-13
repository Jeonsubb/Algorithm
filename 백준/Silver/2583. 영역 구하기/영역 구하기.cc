#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bored[102][102] = { 0 };
bool vis[102][102];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
vector<int>vec; //영역 넣을 친구
int main() {
	int M, N, K; // M은 세로, N은 가로, K는 직사각형 영역 개수
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int num[4];
		for (int j = 0; j < 4; j++) {
			cin >> num[j];
		}

		for (int r = num[1]; r < num[3]; r++) {
			for (int c = num[0]; c < num[2]; c++) {
				bored[r][c] = 1; //직사각형 영역은 1로 채우기
			}
		}
	}

	queue<pair<int, int>>Q; //1을 제외하고 BFS
	int cnt = 0;//영역개수
	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			if (vis[r][c] || bored[r][c] == 1) continue;
			Q.push({ r,c });
			vis[r][c] = 1;
			int area = 0;//넓이
			while (!Q.empty()) {
				pair<int, int>cur = Q.front();
				Q.pop();
				area++; //pop이 생길때마다 영역의 넓이 세는 것
				for (int dis = 0; dis < 4; dis++) {
					int nr = cur.first + dr[dis];
					int nc = cur.second + dc[dis];
					if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
					if (vis[nr][nc] || bored[nr][nc] == 1) continue;
					Q.push({ nr,nc });
					vis[nr][nc] = 1;


				}
				


			}
			cnt++; //BFS 끝났다면 영역을 센것
			vec.push_back(area);

		}
	}

	sort(vec.begin(), vec.end());
	cout << cnt << "\n";
	for (int x : vec) {
		cout << x << " ";
	}




}