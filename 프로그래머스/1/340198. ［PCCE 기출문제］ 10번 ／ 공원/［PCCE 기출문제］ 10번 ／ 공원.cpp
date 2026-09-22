#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool func(int cur, vector<vector<string>> park,int startr,int startc){
    
    for(int i=startr;i<startr+cur;i++){
        for(int j=startc;j<startc+cur;j++){
            //cout << park[i][j];
            if(park[i][j]=="-1") continue;
            else return false;
        }
    }
    
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    //park를 전체 순회하면서 mats에 있는 크기 하나씩을 꺼내서 이만큼의 공간이 있는지 확인을 한다? 
    
    sort(mats.begin(),mats.end(),greater<>());
    cout << park.size()<<" "<<park[0].size();
    //시작위치랑 끝 위치를 옮겨가면서 확인을 한다?
    for(int i=0;i<mats.size();i++){
        int cur = mats[i];
        bool bCur;
        //매트 크기를 하나씩 대입해보자.
        //파크의 가로, 세로를 하나씩 넣으면서 전체 탐색을 해보자.
        //이 때, 매트 크기를 고려해서 가로 인덱스 4부터는 매트를 깔 수 없으니 -cur로 제한을 둔다.
        if(cur>park.size()||cur>park[0].size()) continue;
        
        for(int j=0;j<=park.size()-cur;j++){
            for(int k=0;k<=park[0].size()-cur;k++){
                bCur = func(cur, park,j,k);
                if(!bCur) continue;
                else return cur;
            }   
        }
    }
    
    return answer;
}