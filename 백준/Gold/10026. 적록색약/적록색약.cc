#include <queue>
#include <iostream>
using namespace std;
char bored[102][102];
bool vis1[102][102];
bool vis2[102][102];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int main() {
	int N;
	cin >> N;
	queue<pair<int, int>>Q1; //일반
	queue<pair<int, int>>Q2; //적록색약

	//보드에 각각의 문자 넣기
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			bored[i][j] = str[j];

		}
	}
	int cnt1 = 0; //일반
	int cnt2 = 0; //적록색약

	//파란색 돌리기 -> 공통임
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (vis1[r][c] || bored[r][c] != 'B') continue;
			cnt1++;
			cnt2++;
			Q1.push({ r,c });
			while (!Q1.empty()) {
				pair<int, int>cur = Q1.front();
				Q1.pop();
				for (int i = 0; i < 4; i++) {
					int nr = cur.first + dr[i];
					int nc = cur.second + dc[i];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
					if (vis1[nr][nc] || bored[nr][nc] != 'B') continue;
					vis1[nr][nc] = 1;
					vis2[nr][nc] = 1;
					Q1.push({ nr,nc });
				}

			}
		}
	}

	// 일반인 빨간색 돌리기
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (vis1[r][c] || bored[r][c] != 'R') continue;
			cnt1++;
			Q1.push({ r,c });
			while (!Q1.empty()) {
				pair<int, int>cur = Q1.front();
				Q1.pop();
				for (int i = 0; i < 4; i++) {
					int nr = cur.first + dr[i];
					int nc = cur.second + dc[i];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
					if (vis1[nr][nc] || bored[nr][nc] != 'R') continue;
					vis1[nr][nc] = 1;
					Q1.push({ nr,nc });
				}

			}
		}
	}

	// 일반인 초록색 돌리기
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (vis1[r][c] || bored[r][c] != 'G') continue;
			cnt1++;
			Q1.push({ r,c });
			while (!Q1.empty()) {
				pair<int, int>cur = Q1.front();
				Q1.pop();
				for (int i = 0; i < 4; i++) {
					int nr = cur.first + dr[i];
					int nc = cur.second + dc[i];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
					if (vis1[nr][nc] || bored[nr][nc] != 'G') continue;
					vis1[nr][nc] = 1;
					Q1.push({ nr,nc });
				}

			}
		}
	}

	

	// 적록색약 초록색, 빨간색 돌리기
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (vis2[r][c] || bored[r][c] == 'B') continue;
			cnt2++;
			Q2.push({ r,c });
			while (!Q2.empty()) {
				pair<int, int>cur = Q2.front();
				Q2.pop();
				for (int i = 0; i < 4; i++) {
					int nr = cur.first + dr[i];
					int nc = cur.second + dc[i];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
					if (vis2[nr][nc] || bored[nr][nc] == 'B') continue;
					vis2[nr][nc] = 1;
					Q2.push({ nr,nc });
				}

			}
		}
	}

	cout << cnt1 << " " << cnt2;





}