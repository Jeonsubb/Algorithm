#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string,int> idx;
    int n = friends.size();
    
    for(int i=0;i<n;i++){
        idx[friends[i]] = i;
    }
    
    vector<vector<int>> v(n,vector<int>(n,0));
    vector<int> score(n,0);
    for(auto& a:gifts){
        stringstream ss(a);
        
        string gi, re;
        ss >> gi >> re;
        v[idx[gi]][idx[re]]++;
        score[idx[gi]] ++;
        score[idx[re]] --;
    }
    vector<int> gift(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]>v[j][i]) gift[i]++;
            else if(v[i][j]==v[j][i]){
                if(score[i]>score[j]) gift[i]++;
            }
        }
    }
    answer = *max_element(gift.begin(),gift.end());    
    return answer;
}