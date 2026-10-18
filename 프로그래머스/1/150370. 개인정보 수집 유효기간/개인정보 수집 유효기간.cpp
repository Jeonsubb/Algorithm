#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;
int calc(string s, int a){
    return stoi(s.substr(0,4))*12*28 + stoi(s.substr(5,2))*28 + stoi(s.substr(8,2)) + a*28;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    //각 약관에 대한 숫자들 저장하기
    unordered_map<string, int> m;
    for(auto& s:terms){
        m[s.substr(0,1)] = stoi(s.substr(2));
    }
    
    //현재 날짜를 일수로 아예 바꿔버리기
    int cur = calc(today,0);
    
    for(int i=0;i<privacies.size();i++){
        string nxt = privacies[i].substr(0,10);
        int nxt_c = m[privacies[i].substr(11,1)];
        
        if(cur >= calc(nxt,nxt_c)) answer.push_back(i+1);
        else continue;
    }
    
    return answer;
}