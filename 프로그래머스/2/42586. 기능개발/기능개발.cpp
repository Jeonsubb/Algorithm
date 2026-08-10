#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> answer;
    queue<int> q;
    
    
    //100% 초과까지 얼마나 걸리는지를 q에 삽입
    for(int i=0;i<speeds.size();i++){
        int cur = progresses[i];
        int days=0;
        while(cur<100){
            cur+=speeds[i];
            days++;
        }
        //cout << days << "\n";
        q.push(days);
    }
    
    int cur_d=q.front();
    q.pop();
    int cnt=1;
    while(!q.empty()){
        int nxt_d=q.front();
        q.pop();
        if(cur_d>=nxt_d) cnt++;
        
        else{
            answer.push_back(cnt);
            cur_d = nxt_d;
            cnt=1;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}