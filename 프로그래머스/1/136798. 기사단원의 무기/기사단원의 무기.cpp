#include <string>
#include <vector>

using namespace std;
int cal(int a){
    int cnt=0;
    for(int i=1;i<=a;i++){
        if(a%i==0) cnt++;
    }
    
    return cnt;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1;i<=number;i++){
        int c = cal(i);
        if(c>limit) answer+=power;
        else answer+=c;
    }
    return answer;
}