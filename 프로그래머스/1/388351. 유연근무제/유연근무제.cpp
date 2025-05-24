#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    //경계 시간 값 찾기
    vector<int> t;
    for(int a:schedules){
        if((a%100)+10>=60){
            t.push_back(a+100-50);         //시간 +1 , 분에서는 -50
        }
        else{
            t.push_back(a+10);
        }
    }
    
    //주말까지의 날짜 찾기
    int days=startday;
    bool to = false;
    bool il = false;
    if(days==6) to = true;
    if(days==7) il = true;
    int cnt=0;
    while(1){
        if(days<6) {
            days++;
            cnt++;
        }
        else break;
    }
    
    //출근 체크
    for(int i=0;i<t.size();i++){            //명수
        bool chk = false;                   //지각체크
        
        
        for(int j=0;j<7;j++){               //날짜는 어차피 7일
            //주말에 이벤트 시작
            if(to||il){
                if(to&&!il){                //토요일
                    if(j==0||j==1) continue;      //토요일
                    
                }
                else{
                    if(j==0||j==6) continue;      //일요일,토요일
                }
            }
            
            //평일에 시작
            else{
                if((j-cnt)>=0&&(j-cnt)<=1) continue;     //토요일 또는 일요일
            }
            
            if(t[i]<timelogs[i][j]) {
                chk=true;
                break;   
            }
            else continue;
        }
        if(!chk) answer++;
    }
    
    return answer;
}