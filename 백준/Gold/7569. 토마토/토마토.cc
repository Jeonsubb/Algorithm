//시작점이 여러개일 때!
//다만 삼차원일 때! ----> 삼차원이면 tuple을 사용!
#include <queue>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
int brd[102][102][102]; //z축, y축, x축
bool vis[102][102][102];
int dis[102][102][102];

//방향 결정하는 배열 x y z이고 배열 크기는 6이 될 것!
int dx[6] = { 1,0,-1,0,0,0 }; 
int dy[6] = { 0,1,0,-1 ,0,0};
int dz[6] = { 0,0,0,0,1,-1};
int main() {
	int N, M,H;
	cin >> N >> M >> H;
	queue<tuple< int, int, int>> Q; //이제는 삼차원!

	//1을 큐에 넣기! ....그런데! 삼차원을 곁들인....
	for (int h = 0; h < H; h++) { //z
		for (int i = 0; i < M; i++) { //y
			for (int j = 0; j < N; j++) { //x
				cin >> brd[h][i][j];
				dis[h][i][j] = -1; //-1로 다 채워
				if (brd[h][i][j] == 1) {
					Q.push({ h, i, j });
					vis[h][i][j] = 1;
					dis[h][i][j] = 0;
				}
				else if (brd[h][i][j] == -1) //-1일 때도 0과 구분이 필요함
				{
					dis[h][i][j] = 0;
				}
			}
		}
	}

	while (!Q.empty()) {
		auto front  = Q.front();
		Q.pop();
		//1차 시도 int cnt = 0; //0 주변에 -1이 몇개냐에 따라서 구분할 것임 
		// 2차 시도 -1이 dis 배열에 존재하면 걔한테 못 가는 거니까 -1 출력하도록 변경.
		for (int i = 0; i < 6; i++) {
			int nx = get<2>(front) + dx[i];
			int ny = get<1>(front) + dy[i];
			int nz = get<0>(front) + dz[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz<0||nz>=H) continue;
			if (vis[nz][ny][nx] || brd[nz][ny][nx] != 0) continue;
			//if (brd[ny][nx] == -1) cnt++;
			vis[nz][ny][nx] = 1;
			
			Q.push({nz, ny,nx });
			dis[nz][ny][nx] = dis[get<0>(front)][get<1>(front)][get<2>(front)] + 1;
			
			

		}
		/*if ((cur.second == 0 && (cur.first == 0 || cur.first == M - 1)) || cur.second == N - 1 && (cur.first == 0 || cur.first == M - 1)) {
			if (cnt == 2) {
				cout << -1;
				return 0;
			}
		}
		else if (cur.second == 0 || cur.second == N - 1 || cur.first == 0 || cur.first == M - 1) {
			if (cnt == 3) {
				cout << -1;
				return 0;
			}
		}
		*/
	}

	bool isbreak = false;
	int max = 0;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (dis[h][i][j] >= max) max = dis[h][i][j];
				if (dis[h][i][j] == -1) {
					isbreak = true;
					break;
				}
			}
		}
	}
	if(!isbreak)
	cout << max;
	else {
		cout << -1;
	}

}