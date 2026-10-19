#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    //덱큐 사용 why? min_element 함수를 일반 큐는 지원을 안해줌. 
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto& i:score){
        pq.push(i);
        if(pq.size()>k){
            pq.pop();
        }
        
        answer.push_back(pq.top());
    }
    return answer;
}