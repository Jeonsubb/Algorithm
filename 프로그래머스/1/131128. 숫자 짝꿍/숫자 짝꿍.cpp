#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    int cx[10] = {0};
    int cy[10] = {0};
    for(auto c:X) cx[c-'0']++;
    for(auto c:Y) cy[c-'0']++;
    
    string answer = "";
    
    for(int d=9;d>=0;d--){
        answer+=string(min(cx[d],cy[d]),'0'+d);
    }
    if(answer.empty()) return "-1";
    if(answer[0]=='0') return "0";
    return answer;
}