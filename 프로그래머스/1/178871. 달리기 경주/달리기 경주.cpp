#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer=players;
    
    
    //이터레이터를 <iterator> 라이브러리에 있는 메소드 distance를 사용해서 index로 바꿀 수 있다는 거 알고 있어야겠다.
//     for(int i=0;i<callings.size();i++){
//         auto it =find(answer.begin(),answer.end(),callings[i]);
//         int idx = distance(answer.begin(),it);
//         string temp = answer[idx-1];
//         answer[idx-1] = answer[idx];
//         answer[idx] = temp;
//     }
  
    //위와 같은 접근으로는 시간 초과 발생함. -> 이런 문자열 기반 문제에서는 unordered_map이 대장임. 해시!
    unordered_map<string,int> m;
    
    //해시에 각 선수 이름과 인덱스 넣기..
    for(int i=0;i<players.size();i++){
        m[players[i]] = i;
    }
    
    for(int i =0; i<callings.size();i++){
        
        //해시 맵 이용
        int idx = m[callings[i]];
        string temp = answer[idx-1];
        answer[idx-1] = callings[i];
        answer[idx] = temp;
        
        //map 인덱스 조정
        m[temp] = idx;
        m[callings[i]] = idx-1;
        
    }
    return answer;
}