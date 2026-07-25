#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //int t = commands.size();
    //cout << t;
    
 
    for(auto& i:commands){
            //cout << i[0] << i[1] << i[2];
        vector<int> v;
        int idx=0;
        for(int j=i[0];j<=i[1];j++){
            v.push_back(array[j-1]);
            cout << v[idx];
            idx++;
        }
        sort(v.begin(),v.end());
        answer.push_back(v[i[2]-1]);   
    }
    
    
    return answer;
}