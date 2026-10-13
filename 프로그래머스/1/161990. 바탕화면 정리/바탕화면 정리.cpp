#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    //가장 왼쪽, 가장 위, 가장 오른쪽, 가장 아래쪽
    int sx=51;
    int ex=-1;
    int sy=51;
    int ey=-1;
    
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j]=='#'){
                cout << i <<" " <<j << "\n";
                if(sx>j) sx=j;
                if(ex<j) ex=j;
                if(sy>i) sy=i;
                if(ey<i) ey=i;
            }
            else continue;
        }
    }
    
    answer.push_back(sy);
    answer.push_back(sx);
    answer.push_back(ey+1);
    answer.push_back(ex+1);
    return answer;
}