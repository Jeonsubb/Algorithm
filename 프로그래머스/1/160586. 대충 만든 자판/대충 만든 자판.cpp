#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    unordered_map<char,int> m;
    
    for(auto& s:keymap){
        int tep=1;
        for(auto& c:s){
            auto it = m.find(c);
            //없다면?
            if(it==m.end())m[c]=tep;
            //있다면?
            else{
                if(it->second > tep) m[c] = tep;
            }
            
            tep++;
                    
        }
    }
    
    for(auto& s:targets){
        bool isbreak=false;
        int cnt=0;
        
        for(auto& c:s)
        {
            auto it = m.find(c);
            
            if(it==m.end()) 
            {
                answer.push_back(-1);
                isbreak=true;
                break;
            }
            
            else cnt+=m[c];
        }
            if(!isbreak) answer.push_back(cnt);
    }
    
    return answer;
}