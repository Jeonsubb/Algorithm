#include <string>
#include <vector>
#include <iostream>
using namespace std;

int brd[51][51];
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int w = park[0].size();
    int h = park.size();
    //시작 지점과 보드 채우기
    int ridx,cidx;
    for(int j=0;j<park.size();j++){
        for(int i=0;i<park[j].size();i++){
            if(park[j][i]=='S'){
                ridx=j;
                cidx=i;
                brd[j][i]=1;
            }
            else if(park[j][i]=='O'){
                brd[j][i] = 1;
            }
            else{
                brd[j][i] = 0;
            }
        }
    }
    //cout << ridx << " " << cidx;
    //cout << w << " " << h;
    for(auto& a:routes){
        int nx=0;
        int ny=0;
        int dir = 0;
        if(a[0]=='E'){
            nx += a[2] - '0';
            dir=1;
        }
        else if(a[0] == 'S'){
            ny += a[2] - '0';
            dir=2;
        }
        else if(a[0]=='W'){
            nx -= (a[2] - '0');
            dir=3;
        }
        else{
            ny -=a[2]-'0';
            dir=4;
        }
        int nridx=ridx;
        int ncidx=cidx;
        bool isbreak=false;
        while(nx!=0||ny!=0){
            if(dir==1){
                ncidx++;
                if(ncidx<0||ncidx>w-1) { isbreak=true; break;} 
                if(brd[nridx][ncidx]==0) { isbreak=true; break;}
                //cidx=ncidx;
                nx--;
            }
            else if(dir==2){
                
                nridx++;
                if(nridx<0||nridx>h-1) { isbreak=true; break;}
                if(brd[nridx][ncidx]==0) { isbreak=true; break;}
                //ridx=nridx;
                ny--;
            }
            else if(dir==3){
                
                ncidx--;
                if(ncidx<0||ncidx>w-1) { isbreak=true; break;}
                if(brd[nridx][ncidx]==0) { isbreak=true; break;}
                //cidx=ncidx;
                nx++;
            }
            else{
                
                nridx--;
                if(nridx<0||nridx>h-1) { isbreak=true; break;}
                if(brd[nridx][ncidx]==0) { isbreak=true; break;}
                //cidx=ncidx;
                ny++;
            }
        }
        
        if(isbreak==false){
            ridx=nridx;
            cidx=ncidx;
        }
        cout << ridx << " " << cidx << "\n";
    }
    
    answer.push_back(ridx);
    answer.push_back(cidx);

    return answer;
}