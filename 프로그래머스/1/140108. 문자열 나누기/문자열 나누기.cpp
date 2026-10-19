#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    char fir='0';
    
    for(int i=0;i<s.size();i++){
        if(fir=='0'){
            fir = s[i];
            cnt1++;
        }
        else{
            if(s[i]==fir){
                cnt1++;   
            }
            else{
                cnt2++;
            }
        }
        
        if(cnt1==cnt2){
            cnt1=0;
            cnt2=0;
            answer++;
            fir='0';
        }
        
    }
    
    if(cnt1!=0||cnt2!=0) answer++;
    
    return answer;
}