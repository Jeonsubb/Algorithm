#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int func1(vector<int> v){
    int cnt=1;
    int answer=0;
    for(int i=0;i<v.size();i++){
        if(cnt==1 && v[i]==1) 
            answer++;
            
        if(cnt==2 && v[i]==2) 
            answer++;
            
        if(cnt==3 && v[i]==3) 
            answer++;
            
        
        if(cnt==4 && v[i]==4) 
            answer++;
            
        if(cnt==5) {
            cnt=1;
            if(v[i]==5) answer++;
            continue;
        }
        cnt++;
    }
    return answer;
}

int func2(vector<int> v){
    int cnt=1;
    int answer=0;
    for(int i=0;i<v.size();i++){
        if(cnt==1 && v[i]==2) answer++;
        if(cnt==2 && v[i]==1) answer++;
        if(cnt==3 && v[i]==2) answer++;
        if(cnt==4 && v[i]==3) answer++;
        
        if(cnt==5 && v[i]==2) answer++;
        if(cnt==6 && v[i]==4) answer++;
        if(cnt==7 && v[i]==2) answer++;
        if(cnt==8) {
            cnt=1;
            if(v[i]==5) answer++;
            continue;
        }
        cnt++;
    }
    return answer;
}
int func3(vector<int> v){
    int cnt=1;
    int answer=0;
    for(int i=0;i<v.size();i++){
        if(cnt==1 && v[i]==3) answer++;
        if(cnt==2 && v[i]==3) answer++;
        if(cnt==3 && v[i]==1) answer++;
        if(cnt==4 && v[i]==1) answer++;
        if(cnt==5 && v[i]==2) answer++;
        if(cnt==6 && v[i]==2) answer++;
        if(cnt==7 && v[i]==4) answer++;
        
        if(cnt==8 && v[i]==4) answer++;
        if(cnt==9 && v[i]==5) answer++;
        if(cnt==10) {
            cnt=1;
            if(v[i]==5) answer++;
            continue;
        }
        cnt++;
    }
    return answer;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> c;
    c.push_back(func1(answers));
    
    c.push_back(func2(answers));
    
    c.push_back(func3(answers));
    
    int max=0;
    int idx;
    for(int i=0;i<3;i++){
        cout << c[i] << "\n";
        if(max<c[i]) {
            max=c[i];
            idx=i;
        }
    }
    
    answer.push_back(idx+1);
    
    for(int i=0;i<3;i++){
        if(max==c[i]&&i!=idx) answer.push_back(i+1);
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}