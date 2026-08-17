#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    //최소 우선순위 큐
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    
    //큐에 넣기
    for(auto& a:scoville) pq.push(a);
    
    while(!pq.empty()){
        
        long long scov1 = pq.top(); 
        pq.pop();
        
        long long scov2;
        if(!pq.empty()){
            scov2 = pq.top(); 
            pq.pop();
        }
        else{
            if(scov1<K) return -1;
        }
        
        
        
        if(scov1 < K) {
            long long tmp = scov1+scov2*2;
            pq.push(tmp);
            answer++;
        }
        //else if(scov1 < K && scov2 >= K) return -1;
        
        else return answer;
    }
    
    
    return answer;
}