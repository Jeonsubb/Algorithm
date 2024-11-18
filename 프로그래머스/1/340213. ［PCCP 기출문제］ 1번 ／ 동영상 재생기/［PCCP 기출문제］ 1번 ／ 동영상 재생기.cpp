#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int an_mm=stoi(pos.substr(0,2));
    int an_ss=stoi(pos.substr(3,2));
    
    int ops_mm = stoi(op_start.substr(0,2));
    int ops_ss = stoi(op_start.substr(3,2));
    
    int ope_mm = stoi(op_end.substr(0,2));
    int ope_ss = stoi(op_end.substr(3,2));
    
    
    int vd_mm = stoi(video_len.substr(0,2));
    int vd_ss = stoi(video_len.substr(3,2));
    
    if((ops_mm*60 + ops_ss)<=(an_mm*60 + an_ss) && (ope_mm*60 + ope_ss) >= (an_mm*60 + an_ss)) {
        an_mm = ope_mm;
        an_ss = ope_ss;
    } 
    //명령어들을 다 수행하고 났을 때 결과가 오프닝 구간 안이라면 끝으로 이동 -> 명령어 수행 전에도 오프닝 구간이라면 자동 이동해야 됨.
    for(string str:commands){
        if(str=="prev"){
            if(an_mm == 0 && an_ss <=10) an_ss = 0;
            else if(an_mm != 0 && an_ss <10){
                an_mm = an_mm-1;
                an_ss = an_ss+50;
            }
            else if(an_mm != 0 && an_ss >=10){
                an_ss = an_ss -10;
                
            }
            else if(an_mm == 0 && an_ss >10){
                an_ss = an_ss -10;
                
            }
            
        }
        else if(str=="next"){
            if((vd_mm*60 + vd_ss)-(an_mm*60 + an_ss) <=10 ) {
                an_mm = vd_mm;
                an_ss = vd_ss;
                
            }
            else if(an_ss +10 >= 60){
                an_mm = an_mm+1;
                an_ss = an_ss - 50;
            }
            else if(an_ss+10 <60){
                an_ss = an_ss +10;
                
            }
            
        }
        
    if((ops_mm*60 + ops_ss)<=(an_mm*60 + an_ss) && (ope_mm*60 + ope_ss) >= (an_mm*60 + an_ss)) {
        an_mm = ope_mm;
        an_ss = ope_ss;
    } 
        
    }
    
    string new_an_ss;
    string new_an_mm;
    if(an_ss<10) new_an_ss = "0" + to_string(an_ss);
    else new_an_ss = to_string(an_ss);
    
    if(an_mm<10) new_an_mm = "0" + to_string(an_mm);
    else new_an_mm = to_string(an_mm);
    
    answer = new_an_mm + ":" + new_an_ss;
    return answer;
}