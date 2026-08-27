#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    for(char c:number){
        while(k>0 && !s.empty() && s.top()<c){
          s.pop();
            k--;
        }
        s.push(c);
    }
    while(k>0) {s.pop(); k--;}
    
    while(!s.empty()) {answer += s.top(); s.pop();}
    
    reverse(answer.begin(),answer.end());
    return answer;
}