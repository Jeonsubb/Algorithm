#include <string>
#include <vector>

using namespace std;
int answer = 0;
vector<int> brd;
vector<int> chk;
void func(int k,int sum, int idx){
    if(k==3){
        if(sum==0) {
            answer++;
            return;
        }
        else return;
    }
    
    for(int i=idx;i<brd.size();i++){
        chk.push_back(brd[i]);
        func(k+1,sum+brd[i],i+1);
        chk.pop_back();
    }
}
int solution(vector<int> number) {
    brd = number;
    func(0,0,0);
    return answer;
}