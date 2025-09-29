#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
#define X first
#define Y second
int brd[1005][1005];
int dist[1005][1005][2] = { 0, }; //거리까지 담아두는 삼차원배열 

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	//행렬 넣기
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) 
		{
			brd[i][j] = row[j] - '0';
		}
	}

	queue<tuple<int,int,int>> q; //부쉈는지, 좌표(x,y)
	q.push({ 0, 0,0 });
	dist[0][0][0] = 1;
	
	
	while (!q.empty()) {

		//튜플 사용법 기억하기
		tuple<int,int,int> cur = q.front();
		int curX, curY, broken;
		tie(curX, curY, broken) = cur;
		
		q.pop();


		//BFS는 항상 최단거리를 보장함... 만약 어떤 경로가 도착지에 먼저 도착한다면 걔가 최단거리임.
		if (curX== n - 1 && curY == m - 1) {
			std::cout << dist[curX][curY][broken];
			return 0;
		}


		for (int i = 0; i < 4; i++) {
			int rdx = curX + dr[i];
			int cdx = curY + dc[i];
			pair<int, int> nxt = { rdx,cdx };


			if (nxt.X < 0 || nxt.X >= n || nxt.Y < 0 || nxt.Y >= m) continue;
			
			//벽이랑 만남
			if (brd[nxt.X][nxt.Y] == 1)
			{
				if (broken != 1 && dist[nxt.X][nxt.Y][1]==0) //벽을 안 부쉈어 ,, &&으로 체크하는 이유는 벽을 부수고 해당 지점에 도달한 BFS가 있을 수도 있으니
				{

					q.push({ nxt.X,nxt.Y,1 } );

					dist[nxt.X][nxt.Y][broken + 1] = dist[curX][curY][broken] + 1;

				}
				else continue; //부쉈으면 넘어가
			}
			else //벽은 아님
			{
				//지나가는 거니 거리만 기록
				if (dist[nxt.X][nxt.Y][broken]!=0) continue;
				dist[nxt.X][nxt.Y][broken] = dist[curX][curY][broken] + 1;
				q.push({ nxt.X,nxt.Y,broken });
			}
			
		}
	}

	std::cout << -1;
	return 0;

	
	
}