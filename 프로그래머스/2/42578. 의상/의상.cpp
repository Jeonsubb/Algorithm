#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    
    //해시에 키는 상세 옷이랑 값은 각각의 종류 넣기
    for(auto& cloth:clothes){
        m[cloth[1]]++; 
        
    }
    
    for(auto& [key,value]:m) answer *= value+1;
    
    return answer-1;
}