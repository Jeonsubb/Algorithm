#include <string>
#include <vector>
#include <queue>

using namespace std;

//int chk[201][201] = {0,};
//int rx[4] = {1,0,-1,0};
//int ry[4] = {0,1,0,-1};


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    /*
    110
    110
    001
        
    110
    111
    011
    
    100
    010
    001
    */
    
    
//     queue<pair<int,int>>q;
    
//     //모든 점들을 다 돌도록
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             //연결이면서 방문하지 않은 곳
//             if(computers[i][j]==1&&chk[i][j]==0){
//                 q.push({i,j});
//                 answer++;
//                 while(!q.empty()){
//                     pair<int,int> cur = q.front();
//                     q.pop();
//                     for(int i=0;i<4;i++){
//                         pair<int,int> nxt;
//                         nxt.first = cur.first + rx[i];
//                         nxt.second = cur.second + ry[i];
//                         if(nxt.first<0||nxt.first>=n||nxt.second<0||nxt.second>=n) continue;
//                         if(chk[nxt.first][nxt.second]==1) continue;
//                         if(computers[nxt.first][nxt.second]==0) continue;
//                         q.push({nxt.first,nxt.second});
//                         chk[nxt.first][nxt.second]=1;
//                     }
//                 }
//             }
//         }
//     }
        
    //격자로 봐서 틀렸고 인접 행렬로 생각해야 됨
    vector<bool> chk(n,false);
    for(int i=0;i<n;i++){
        if(chk[i]) continue;
        answer++;
        queue<int>q;
        q.push(i);
        chk[i]=true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(computers[cur][j]==0) continue;
                if(chk[j]) continue;
                q.push(j);
                chk[j]=true;
            }
        }
    }
    return answer;
}