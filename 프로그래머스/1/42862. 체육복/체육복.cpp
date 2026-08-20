#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //작은 숫자 우선으로 해야 되네
    
    answer = n -lost.size();
    
    sort(lost.begin(),lost.end());
    
    bool chk[31] = {false};
    
    for(auto& a:lost){
        if(find(reserve.begin(),reserve.end(),a) != reserve.end() && chk[a] == false) {
            answer++;
            chk[a] = true;
            continue; //자기 여벌봇 처리

        }
        
    }
    
    for(auto& a:lost){
        
        //작은 숫자를 먼저 확인하고, chk에서 쓴적이 없는 숫자면 빌려주는 거 맞음
        if(chk[a]==true) continue;
        
        if(find(reserve.begin(),reserve.end(),a-1) != reserve.end() && chk[a-1]==false){
            answer++;
            chk[a-1] = true;
        }
        else if(find(reserve.begin(),reserve.end(),a+1) != reserve.end() && chk[a+1]==false){
            answer++;
            chk[a+1] = true;
        }
        else continue;
    }
    return answer;
}