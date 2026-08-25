#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    //벡터 우선순위랑 a,b,c,d... 를 나타내는 0,1,2 숫자를 큐에 동시에 넣는다? 벡터를 계속 순차 검색을 해서 우선순위가 더 큰게 있는지 매번 찾는다?
    queue<pair<int,int>> q;
    
    queue<int> pq; //우선순위만 넣기?
    
    
    for(int i=0;i<priorities.size();i++){
        q.push({i,priorities[i]});
    }
    sort(priorities.begin(),priorities.end(),greater<int>());
    
    for(int i=0;i<priorities.size();i++) pq.push(priorities[i]);
    
    vector<int> v;
    while(!pq.empty()){
        pair<int,int> cur = q.front();
        int m = pq.front();
        
        //우선순위 최대값일 때
        if(cur.second == m){
            pq.pop();
            v.push_back(cur.first);
            q.pop();
        }
        //최대값이 아닐 때
        else{
            q.pop();
            q.push(cur);
        }
        cout << cur.first << " " << cur.second << "\n";
    }
    cout << q.size();
    //vector<int> v;
    // while(!q.empty()){
    //     pair <int,int> cur = q.front();
    //     q.pop();
    //     v.push_back(cur.first);
    // }
    
    for(int i=0;i<v.size();i++){
        if(v[i]==location) return i+1;
    }
    
    
    return answer;
}