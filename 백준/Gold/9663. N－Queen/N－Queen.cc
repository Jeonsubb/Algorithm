#include <iostream>
using namespace std;
//queen은 같은 행, 같은 열, 오른쪽 아래 오른쪽 위 왼쪽 아래 왼쪽 위 다 못감

int n;
int brd[20][20];
bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt = 0;
//int dr[4] = { 1,1,-1,-1 };
//int dc[4] = { 1,-1,1,-1 };

void func(int k) {
	if (k == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[i + k] || isused3[k - i + n - 1]) continue;
		isused1[i] = 1; //i가 열을 의미
		isused2[i+k] = 1; //i가 열을 의미하고 k가 행을 의미 x+y가 같으면 같은 직선상에 있다는 것을 의미
		isused3[k -i+n-1] = 1; //x-y+n-1을 의미 --> 얘는 x-y가 일정한 값을 가지는걸 사용 대각선들이...
		func(k + 1);
		isused1[i] = 0;
		isused2[i + k] = 0;
		isused3[k - i + n - 1] = 0;

	}
}
//		for (int j = 0; j < n; j++) {
//			if (!isused[i][j]&&brd[i][j]!=1) {
//				brd[i][j] = 1;
//				isused[i][j] = 1;
//				for (int a = 0; a < n; a++)isused[i][a] = 1; //같은 행
//				for (int a = 0; a < n; a++)isused[a][j] = 1; //같은 열
//				int c = 1;
//				while (1) { //대각선 처리
//					if (c == n) break;
//					for (int q = 0; q < 4; q++) {
//						int nr = i + c*dr[q];
//						int nc = j + c*dc[q];
//						if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
//						isused[nr][nc] = 1;
//					}
//					c++;
//
//				}
//				func(k + 1);
//				isused[i][j] = 0;
//				for (int a = 0; a < n; a++)isused[i][a] = 0;
//				for (int a = 0; a < n; a++)isused[a][j] = 0;
//				c = 1;
//				while (1) {
//					if (c == n) break;
//					for (int q = 0; q < 4; q++) {
//						int nr = i + c * dr[q];
//						int nc = j + c * dc[q];
//						if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
//						isused[nr][nc] = 0;
//					}
//					c++;
//
//				}
//			}
//		}
//	}
//}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	func(0);
	cout << cnt;
}