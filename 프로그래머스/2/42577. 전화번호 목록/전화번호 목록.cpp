#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string,bool> m;
    
    //해시맵에 번호들 다 넣기
    for(auto& num:phone_book) m[num]=true;
    
    
    for(auto& num:phone_book){
        //prefix 만들기
        //이때 len이 해당 번호의 전체 보다는 작게 쪼개기
        for(int len=1;len<num.size();len++){
            //앞에서부터 prefix 뽑기
            string sub = num.substr(0,len);
            //해시맵에 해당 prefix가 있는지 확인 -> 있으면 count에서 0보다 큰 값이 나오니깐
            if(m.count(sub)) return false;
        }
    }

    
    
    return true;
}