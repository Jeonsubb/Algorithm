#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int n= friends.size();
    //해시, 문자열 키, idx를 값으로
    unordered_map<string, int> idx;
    
    //각 이름을 인덱스로 바꾸기
    for(int i=0; i< friends.size();i++){
        idx[friends[i]]=i;
    }
    
    //선물 지수 계산할 거, 0으로 초기화하는게 중요
    vector<int> grade(n,0);
    
    //여기도 초기화하는 거 중요한데, 이차원 벡터에서 초기화하는 거 잘 모르니까 유의
    //문자열 공백 기준 바꾸는거 새롭게 안거니까 제대로 하기
    
    vector<vector<int>> cnt(n,vector<int>(n,0));
    for(auto& gift:gifts){
        stringstream ss(gift);
        string t1,t2;
        ss >> t1 >> t2;
        
        cnt[idx[t1]][idx[t2]]++;
        grade[idx[t1]]++;
        grade[idx[t2]]--;
    }
    
    vector<int> c(n,0);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cnt[i][j]>cnt[j][i]) c[i]++;
            //i,j 이중 반복에서 j돌 때 또 한번더 하면 안되는거 조심.
            else if(cnt[i][j]==cnt[j][i] && grade[i]>grade[j])c[i]++;
             
        
        }
    }
    answer=*max_element(c.begin(),c.end());
    
    return answer;
}