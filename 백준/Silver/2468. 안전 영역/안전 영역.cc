#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
int brd[102][102];
bool vis[102][102];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
vector<int>vec;
int bfs(int x ,int n) {
	//vis는 계속 초기화 되어야 함.
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			vis[r][c] = 0;
		}
	}
	int cnt = 0;
	queue<pair<int, int>>Q;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (vis[r][c]||brd[r][c] <= x) continue;
			Q.push({ r,c });
			vis[r][c] = 1;
			cnt++; //Q에 넣기 시작하면 그 영역이 추가되는 거니깐.
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dis = 0; dis < 4; dis++) {
					int nr = cur.first + dr[dis];
					int nc = cur.second + dc[dis];
					if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
					if (vis[nr][nc] || brd[nr][nc] <= x) continue;
					Q.push({ nr,nc });
					vis[nr][nc]=1;
				}
			}
		
		}
	}
	//x보다 큰 영역의 개수를 반환
	return cnt;

}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> brd[i][j];
			vec.push_back(brd[i][j]);
		}
	}

	//벡터에서 중복된 값들 없애는 방법!
	sort(vec.begin(), vec.end());
	auto last = unique(vec.begin(), vec.end()); //중복되는 값들은 다 뒤로 넣음.
	//그러고 중복되는 값 시작점을 반환
	vec.erase(last, vec.end());

	int max_cnt = 1; //비가 아예 안온다면 1임.
	for (int x : vec) {
		max_cnt = max(max_cnt, bfs(x, n));
	}
	cout << max_cnt;

}