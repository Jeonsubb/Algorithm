#include <iostream>
#include <queue>
using namespace std;
char bored[1002][1002]; 
bool vis1[1002][1002];//불
bool vis2[1002][1002];//상근
int dis1[1002][1002];//불 거리
int dis2[1002][1002];//상근 거리
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int main() {
	int T;
	cin >> T;

	while (T > 0) {
		int c,r;
		cin >> c >> r;

		queue<pair<int, int>>Q1;
		queue<pair<int, int>>Q2;

		for (int i = 0; i < r; i++) { //초기화!
			string str;
			cin >> str;
			for (int j = 0; j < c; j++) {
				bored[i][j] = str[j];
				vis1[i][j] = 0;
				vis2[i][j] = 0;
				dis1[i][j] = -1;
				dis2[i][j] = -1; //처음부터 붙어 있는 칸과 구분하기 위해서 다른 숫자로 초기화 해야 됨.

				//상근이 위치 push
				if (bored[i][j] == '@') {
					Q2.push({ i,j });
					vis2[i][j] = 1;
					dis2[i][j] = 0;
				}
				//불 위치 push
				else if (bored[i][j] == '*') {
					Q1.push({ i,j });
					vis1[i][j] = 1;
					dis1[i][j] = 0;
				}
			}
		}


		//불 먼저 BFS 실행
		while (!Q1.empty()) {
			pair<int, int>cur = Q1.front();
			Q1.pop();
			for (int i = 0; i < 4; i++) {
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];

				if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
				if (vis1[nr][nc] || bored[nr][nc] == '#') continue;
				Q1.push({ nr,nc });
				vis1[nr][nc] = 1;
				dis1[nr][nc] = dis1[cur.first][cur.second] + 1;
			}

		}
		bool isbreak = false;

		// 상근이의 시작 위치가 가장자리인지 확인
		if (!Q2.empty()) {
			int sr = Q2.front().first;
			int sc = Q2.front().second;
			if (sr == 0 || sr == r - 1 || sc == 0 || sc == c - 1) {
				cout << 1 << "\n";
				isbreak = true;
			}
		}

		//상근이 BFS 실행
		if (!isbreak) {
			while (!Q2.empty()) {
				pair<int, int>cur = Q2.front();
				Q2.pop();
				for (int i = 0; i < 4; i++) {
					int nr = cur.first + dr[i];
					int nc = cur.second + dc[i];

					//경계에 접근하면 탈출!
					if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
						cout << dis2[cur.first][cur.second] + 1 << "\n";
						isbreak = true;
						break;
					}
					if (vis2[nr][nc] || bored[nr][nc] == '#') continue;
					if (dis1[nr][nc] != -1 && dis2[cur.first][cur.second] + 1 >= dis1[nr][nc]) continue; //같은 시간에 도착하거나 더 느린 시간에 가는 경로라면 못가므로! ,,불이 도달하지 못하는 위치는 배제하고 이동!
					Q2.push({ nr,nc });
					vis2[nr][nc] = 1;
					dis2[nr][nc] = dis2[cur.first][cur.second] + 1;
				}

				if (isbreak) break; //탈출했다면 while도 탈출해야 됨.


			}
		}
		//종료 조건에 도달하지 못 한것은 IMPOSSIBLE
		if (!isbreak) cout << "IMPOSSIBLE" << "\n";



		T--;
	}
}