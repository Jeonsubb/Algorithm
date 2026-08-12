#include<vector>
#include <queue>
#include <iostream>
int chk[101][101]={0,};
int dis[101][101]={0,};
int rx[4] = {1,0,-1,0};
int ry[4] = {0,1,0,-1};


using namespace std;

int solution(vector<vector<int> > maps)
{
    
    int answer = 0;
    int n= maps.size();
    int m= maps[0].size();
    queue<pair<int,int>> q;
    //시작 지점 삽입 -> 벽이면 끝
    if(maps[0][0]==1){ 
        q.push({0,0});
        chk[0][0]=1;
        dis[0][0]=1;
    }
    else {
        answer = -1;
        return answer;
    }
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            pair<int,int> nxt;
            nxt.first = cur.first + rx[i];
            nxt.second = cur.second + ry[i];
            if(nxt.first<0||nxt.first>=n||nxt.second<0||nxt.second>=m) continue;
            if(maps[nxt.first][nxt.second]==0) continue;
            if(chk[nxt.first][nxt.second]==1) continue;
            q.push(nxt);
            chk[nxt.first][nxt.second]=1;
            dis[nxt.first][nxt.second] = dis[cur.first][cur.second]+1;
         }
    }
    
    if(dis[n-1][m-1]==0) answer=-1;
    else answer=dis[n-1][m-1];

    return answer;
}