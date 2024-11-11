//시작점이 두 종류일 때
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
char bored[1002][1002];
bool visitJ[1002][1002];
bool visitF[1002][1002];
int disJ[1002][1002];
int disF[1002][1002];
int drow[4] = {0,1,0,-1};
int dcol[4] = { 1,0,-1,0 };
int main() {
	int R, C;
	cin >> R >> C;
	queue<pair<int, int>>J; //지훈이

	queue<pair<int, int>>F; //불
	for (int i = 0; i < R; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < C; j++) {
			bored[i][j] = row[j];
			disF[i][j] = -1;
			if (bored[i][j] == 'J') {
				visitJ[i][j] = 1;
				J.push({ i,j });
			}
			else if (bored[i][j] == 'F') {
				visitF[i][j] == 1;
				F.push({ i,j });
				disF[i][j] = 0;
			}
		}
	}

	while (!F.empty()) {
		
		pair<int, int>curF = F.front();
		F.pop();

		for (int i = 0; i < 4; i++) {
			int nFr = curF.first + drow[i];
			int nFc = curF.second + dcol[i];
			

			if (nFr < 0 || nFr >= R || nFc < 0 || nFc >= C ) continue;
			if (visitF[nFr][nFc] || bored[nFr][nFc] != '.')continue;
			F.push({nFr,nFc});
			visitF[nFr][nFc] = 1;
			disF[nFr][nFc] = disF[curF.first][curF.second] + 1;
			

		}
	}
	while (!J.empty()) {
		pair<int, int>curJ = J.front();
		J.pop();
		

		for (int i = 0; i < 4; i++) {
			int nJr = curJ.first + drow[i];
			int nJc = curJ.second + dcol[i];

			if (nJr < 0 || nJr >= R || nJc < 0 || nJc >= C) {
				cout << disJ[curJ.first][curJ.second] + 1;
				return 0;
			}
			if (visitJ[nJr][nJc] || bored[nJr][nJc] != '.')continue;
			//현재 기준 상하좌우 +1한게 상하좌우한 불의 거리보다 작아야지 J는 갈 수 있음
			if (disF[nJr][nJc]!=-1 && disJ[curJ.first][curJ.second] + 1 >= disF[nJr][nJc]) continue;
			J.push({ nJr,nJc });
			visitJ[nJr][nJc] = 1;
			disJ[nJr][nJc] = disJ[curJ.first][curJ.second] + 1;


		}
	}
	//위에서 경계에 들어가면 종료하는 조건을 걸어놨으므로 위의 while문 탈출하면
	//종료 조건에 도달하지 못한것이므로 탈출 못한것임.
	cout << "IMPOSSIBLE";

	//밑에는 내가 작성한 코드 근데 이것보다 훨씬 효율적인 코드가 존재함
	//int min = 1000;
	////가장자리에 접하는 것중 1열과 C열의 값 중 0이 아닌 제일 작은 값을 찾음.
	//for (int i = 0; i < R; i++) {
	//	if (disJ[i][0] != 0 && disJ[i][0] <= min) min = disJ[i][0];

	//	if (disJ[i][C-1] != 0 && disJ[i][C-1] <= min) min = disJ[i][C-1];
	//}
	////이제는 열 차례
	//for (int i = 0; i < C; i++) {
	//	if (disJ[0][i] != 0 && disJ[0][i] <= min) min = disJ[0][i];

	//	if (disJ[R-1][i] != 0 && disJ[R-1][i] <= min) min = disJ[R-1][i];
	//}
	//
	////그대로라면 탈출하지 못하는 상황이겠거니
	//if (min == 1000) cout << "IMPOSSIBLE";
	//else cout << min + 1;
	//
	
	
}