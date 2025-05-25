#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    //붕대 감기 기술의 시전 시간, 1초당 회복량, 추가 회복량을 담은 1차원 정수 배열 bandage
    //최대 체력을 의미하는 정수 health
    //몬스터의 공격 시간과 피해량을 담은 2차원 정수 배열 attacks가 매개변수로 주어집니다. 
    int time = bandage[0];
    int plus = bandage[1];
    int pplus = bandage[2];
    int th = health;
    int cnt=0;                              //time과 같아질때까지 증가
    int ctime=0;                            //시간 기록용
    int s=0;                                //공격횟수 비교용
    while(s!=attacks.size()){               //공격 횟수가 끝날떄까지 반복->*
        
        if(ctime==attacks[s][0]){           //공격 생겼을 때
            cnt=0;                          //연속 성공 짤림
            th-=attacks[s][1];              //공격만큼 차감
            if(th<=0) {                     //목숨이 0 이하면 끝
            answer = -1;
            return answer;
            }
            ctime++;                        //시간은 계속 증가
            s++;                            //다음 공격 인덱스로 이동
            //cout << attacks.size() << "\n";
            //cout << "공격자리입니다!!!!!!!!!!\n";
        }
        
        else{
            cnt++;                          //공격이 아닐 때
            if(cnt==time){                  //연속 시간이 같아졌을 때
                cnt=0;                      //횟수 0으로 초기화
                if(th!=health)              //최대 목숨일 때
                {                           //아니라면 증가
                    th+=plus;
                    th+=pplus;
                    if(th>=health) th = health; //증가 시켰는데 커졌다면 최대로 고정
                }
                ctime++;                    //시간은 일정하게 증가
                
                //cout << "공격이 아닌데 연속 성공 했을 때\n";
            }
            
            else{                           //연속 시간이 같지 않을 때
                                            //연속 도달까지 증가
                if(th!=health)              //최대 목숨일 때
                {                           //아니라면 증가
                    th+=plus;
                   if(th>=health) th = health; //증가 시켰는데 커졌다면 최대로 고정
                }
                ctime++;                    //시간은 일정하게 증가
                //cout << "일반적인 상황\n";
            }
        }
        
    }
    
    answer=th;
    
    return answer;
}