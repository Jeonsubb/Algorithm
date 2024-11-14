#include <queue>
#include <iostream>
#include <tuple>
using namespace std;
char brd[31][31][31];
bool vis[31][31][31];
int dis[31][31][31];
int dr[6] = { 0,1,0,-1,0,0 };
int dc[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int l, r, c;
	cin >> l >> r >> c;
	while (l != 0 && r != 0 && c != 0) {

		queue<tuple<int, int, int>>Q;

		//탈출 위치 넣어둘 곳
		auto esca = make_tuple(0,0,0);

		//반복시행이기 때문에 보드와 거리,vis를 초기화해줘야 됨.
		for (int z = 0; z < l; z++) {
			
			for (int y = 0; y < r; y++) {
				string str;
				cin >> str;
				for (int x = 0; x < c; x++) {
					brd[z][y][x] = str[x];
					vis[z][y][x] = 0;
					dis[z][y][x] = -1; //갈 수 없는 곳이 있으니깐
					//상범이 위치
					if (brd[z][y][x] == 'S') {
						Q.push(make_tuple(z,y,x));
						vis[z][y][x] = 1;
						dis[z][y][x] = 0; //0으로 바꾸기
					}

					//출구 위치
					if (brd[z][y][x] == 'E') {
						esca = make_tuple(z, y, x);
					}


				}
			}
		}

		//BFS 시작
		bool isbreak = false;
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			if (get<0>(cur) == get<0>(esca) && get<1>(cur) == get<1>(esca) && get<2>(cur) == get<2>(esca)) {
				//E에 도착하면 끝
				cout <<"Escaped in " << dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] << " minute(s)." << "\n";
				isbreak = true;
				break;
			}

			for (int d = 0; d < 6; d++) {
				int nz = get<0>(cur) + dz[d];
				int nr = get<1>(cur) + dr[d];
				int nc = get<2>(cur) + dc[d];
				if (nz < 0 || nz >= l || nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
				if (vis[nz][nr][nc] || brd[nz][nr][nc] == '#') continue;
				Q.push(make_tuple(nz, nr, nc));
				vis[nz][nr][nc] = 1;
				dis[nz][nr][nc] = dis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			}
		}

		//E에 도착하지 않은채로 끝났다면 탈출 못하는 것임.
		if (!isbreak) {
			cout << "Trapped!" << "\n";
		}

		//다음 반복 수행하기 위한 변수들 입력
		cin >> l >> r >> c;


	}
}