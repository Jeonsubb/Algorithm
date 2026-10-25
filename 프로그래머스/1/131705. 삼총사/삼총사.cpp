#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> brd;
vector<int> chk;
int answer = 0;
void func(int k,int sum,int idx){
    if(k==3){
        if(sum==0) answer++;
        //cout <<"k:"<< k <<" " <<"sum:" << sum <<" " <<"idx:"<<idx<<"\n";
        return;
    }
    
    for(int i=idx;i<brd.size();i++){
        chk.push_back(brd[i]);
        func(k+1,sum+brd[i],i+1);
        chk.pop_back();
    }
}
int solution(vector<int> number) {
    
    brd=number;
    //cout << brd.size()<<"\n";
    func(0,0,0);
    return answer;
}