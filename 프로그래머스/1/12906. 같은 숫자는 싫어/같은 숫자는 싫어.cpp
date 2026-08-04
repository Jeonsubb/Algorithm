#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int>q;
    for(auto& a:arr){
        if(q.empty()) q.push(a);
        else{
            if(q.back()==a) continue;
            else q.push(a);
        }
    }
    
    while(!q.empty()){
        answer.push_back(q.front());
        q.pop();
    }
  

    return answer;
}