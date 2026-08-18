#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n+1);
    for(auto& a:edge){
        adj[a[0]].push_back(a[1]);
        
        adj[a[1]].push_back(a[0]);
    }
    
    queue<int> q;
    //1번 노드와 거리 0으로 시작
    vector<int> dist(n+1,-1);
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<adj[cur].size();i++){
            if(dist[adj[cur][i]] !=-1) continue;
            q.push(adj[cur][i]);
            dist[adj[cur][i]]= dist[cur]+1;
        }
        
    }
    
    int max=0;
    for(int i=0;i<dist.size();i++) if(max<dist[i]) max=dist[i];
    
    for(int i=0;i<dist.size();i++) if(max==dist[i]) answer++;
        
    
    return answer;
}