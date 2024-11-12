#include <queue>
#include <iostream>
using namespace std;
int bored[302][302];
bool vis[302][302];
int dis[302][302];
//나이트의 이동을 다 넣음
int dr[8] = { 2,1,-1,-2,-2,-1,1,2 };
int dc[8] = {1, 2,2,1,-1,-2,-2,-1};

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		int I;
		cin >> I; //체스판 크기

		for (int i = 0; i < I; i++) { //초기화!
			for (int j = 0; j < I; j++) {
				bored[i][j] = 0;
				vis[i][j] = 0;
				dis[i][j] = 0;
			}
		}

		queue<pair<int, int>>Q;

		int r, c;;
		cin >> r >> c;
		bored[r][c] = 1; //현재 위치
		
		int rr, rc;
		cin >> rr >> rc;
		bored[rr][rc] = 2; //목표 위치

		Q.push({ r,c });
		vis[r][c] = 1;

		while (!Q.empty()) { //목표 위치에 도달할 때 까지 반복 
			pair<int, int>cur = Q.front();
			Q.pop();

			if (bored[cur.first][cur.second] == 2) {
				cout << dis[cur.first][cur.second] << "\n";
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];
				if (nr < 0 || nr >= I || nc < 0 || nc >= I) continue;
				if (vis[nr][nc]) continue;
				Q.push({ nr,nc });
				vis[nr][nc] = 1;
				dis[nr][nc] = dis[cur.first][cur.second] + 1;
			}
		}		
		T--;
	}
}