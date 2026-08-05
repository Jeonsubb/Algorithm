#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    //queue<int> q;
    stack<pair<int,int>> s;
    
    //초기값 넣기
    s.push({0,0});
        
    
    //이제 돌기 시작 앞에는 넣은 개수, 뒤에는 지금까지의 합
    while(!s.empty()){
        auto [idx,sum]=s.top();
        s.pop();
        if(idx==numbers.size()){
            if(sum==target) answer++;
        }
        else{
            s.push({idx+1,sum+numbers[idx]});
            s.push({idx+1,sum-numbers[idx]});
        }
    }
     
    return answer;
}