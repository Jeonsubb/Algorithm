#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    int n = s.size();
    vector<int> answer(n,0);
    unordered_map<char, int> m;
    
    
    //해시맵에 가장 최근의 인덱스를 넣으면서 answer까지 바로바로 반영하기
    for(int i=0;i<n;i++){
        //없다면?
        if(m.find(s[i])==m.end()){
            m[s[i]] = i;
            answer[i] = -1;
        }
        //있다면?
        else{
            //해시맵에 저장되어 있는 인덱스와 현재 인덱스의 차로 거리를 답에 넣기
            answer[i] = i-m[s[i]];
            //해시맵은 가장 최근 거리로 바꾸기
            m[s[i]] = i;
        }
    }
    return answer;
}