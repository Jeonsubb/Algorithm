#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> w={"aya","ye","woo","ma"};
    
    for(auto& s:babbling){
        int i=0;
        int prev= -1;
        bool ok = true;
        
        while(i<s.size()){
            int found = -1;
        for(int j=0;j<4;j++){
            
            if(s.compare(i,w[j].size(),w[j])==0)
            {
                i+=w[j].size();
                found=j;
                break;
            }
        }
            if(found==-1||found==prev) {ok=false; break;}
            
            prev=found;
            
        }
        
        if(ok) answer++;
    }
    
    return answer;
}