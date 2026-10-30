#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    //양수 음수 나눠서 생각
    
    //RT,TR은 0 , CF,FC는 1, JM,MJ는 2, AN,NA는 3
    vector<int> m(4,0);
    
    for(int i=0;i<survey.size();i++){
        if(survey[i]=="RT" || survey[i]=="TR"){
            if(survey[i]=="RT"){
                int n = choices[i] - 4;
                m[0]+=n;
            }
            else{
                int n = 4-choices[i];
                m[0]+=n;
            }
        }
        else if(survey[i]=="CF" || survey[i]=="FC"){
            if(survey[i]=="CF"){
                int n = choices[i] - 4;
                m[1]+=n;
            }
            else{
                int n = 4-choices[i];
                m[1]+=n;
            }
        }
        else if(survey[i]=="JM" || survey[i]=="MJ"){
            if(survey[i]=="JM"){
                int n = choices[i] - 4;
                m[2]+=n;
            }
            else{
                int n = 4-choices[i];
                m[2]+=n;
            }
        }
        else{
            if(survey[i]=="AN"){
                int n = choices[i] - 4;
                m[3]+=n;
            }
            else{
                int n = 4-choices[i];
                m[3]+=n;
            }
        }
    }
    
    for(int i=0;i<4;i++){
        if(i==0){
            if(m[i]>0) answer+="T";
            else answer+="R";
        }
        else if(i==1){
            if(m[i]>0) answer+="F";
            else answer+="C";
        }
        else if(i==2){
            if(m[i]>0) answer+="M";
            else answer+="J";
        }
        else{
            if(m[i]>0) answer+="N";
            else answer+="A";
        }
        
    
    }
    
    
    
    return answer;
}