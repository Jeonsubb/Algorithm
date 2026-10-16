#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    
    //각 카드들의 단어들을 해시맵에 저장함. 이때 단어들의 순서가 중요하니 인덱스를 함께 넣기
    int i=0;
    for(auto& s:cards1){
        m1[s]=i;
        i++;
    }
    
    i=0;
    for(auto& s:cards2){
        m2[s]=i;
        i++;
    }
    
    int cur1 = -1;
    int cur2 = -1;
    //목표 문장의 각 단어들을 하나씩 가져와서 해시맵에 존재하는지 확인. 이때 서로 다른 단어만 존재하니까 중복 단어의 순서 문제 같은건 고려 안해도 됨.
    for(auto& s:goal){
        auto it1 = m1.find(s);
        auto it2 = m2.find(s);
        
        if(it1!=m1.end()) {
            if(it1->second == cur1+1) {
                cur1 = it1->second;
                continue;   
            }
            else{
                answer="No";
                return answer;
            }
        }
        
        
        if(it2!=m2.end()){
            if (it2->second == cur2+1){
                cur2 = it2->second;
                continue;   
            }
            else{
                answer="No";
                return answer;
            }
        }
        
        //if(it1==m1.end()&&it2==m2.end())
        answer="No";
        return answer;
        
    }
    
    answer = "Yes";
    return answer;
}