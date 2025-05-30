#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int wr = wallet[0];
    int ws = wallet[1];
    int br = bill[0];
    int bs = bill[1];
    bool garo = false;
    bool sero = false;
    
    //둘다 통과 될때까지 접기
    while(!garo&&!sero){
        //둘 중 하나라도 지갑보다 크다면
        if(wr<br||ws<bs){
            if(br>bs){
                
                br /= 2;
                answer++;
                if(wr>=bs&&ws>=br) break;
            }
            else{
                bs /= 2;
                answer++;
                if(wr>=bs&&ws>=br) break;
            }
        }
        
        else return answer;
           
        
        
        
    }
    return answer;
}