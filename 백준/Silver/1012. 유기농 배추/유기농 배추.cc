#include <iostream>
#include <queue>
using namespace std;

bool vis[52][52];
int bored[52][52] = { 0 }; /////지역 변수에 할당하면 스택 오버플로우가 발생해서 안되는것! -> 전역 변수에 할당해야 전역 메모리를 쓰는 것!
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		
		int r, c, n;
		cin >> c >> r >> n;

		// 각 테스트 케이스마다 배열 초기화
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				vis[i][j] = false;
				bored[i][j] = 0;
			}
		}

		queue<pair<int, int>>Q;
		int cnt = 0; //배추 심어져 있는 곳
		//배추 있는 곳 표시
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			bored[y][x] = 1;
			
		}

		
		//이중 반복문 돌리면서 배추 위치 찾으면 큐에 넣고 BFS 실행

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				
				if (bored[i][j] != 1||vis[i][j]) continue;
				Q.push({ i,j });
				vis[i][j] = 1;
				cnt++;
				while (!Q.empty()) {
					
					pair<int, int>cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nr = cur.first + dr[k];
						int nc = cur.second + dc[k];
						if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
						if (vis[nr][nc] || bored[nr][nc] != 1) continue;
						vis[nr][nc] = 1;
						Q.push({ nr,nc });
					}

				}

				
			}

		}

		cout << cnt << "\n";
	}

}