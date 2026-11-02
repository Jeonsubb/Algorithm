#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    
    vector<int> answer(n,0);
    unordered_map<string,int> idx; //인덱스 처리
    unordered_map<string,int> cnt; //신고 횟수 처리
    unordered_map<string,int> isre; //중복 신고인지 확인
    
    int id = 0;
    for(auto& s:id_list){
        idx[s] = id;
        id++;
        cnt[s] = 0;
    }
    
    for(auto& s:report){
        string f,b;
        stringstream ss(s);
        ss >> f >> b;
        
        //isre에 없으면 넣기
        if(isre.find(s)==isre.end()){
        //이거 됐나? 되네
        //동일인의 신고는 한건으로 처리 된다를 고려 안함.
        cnt[b]++;
        isre[s] = 1;
        }
        else continue;
        
    }
    for(auto& s:report){
        string f,b;
        stringstream ss(s);
        ss >> f >> b;
        
        if(cnt[b] >= k){
            if(isre[s]==1){
            answer[idx[f]]++;
            isre[s]--;
            }
        }
        
    }
    
    return answer;
}