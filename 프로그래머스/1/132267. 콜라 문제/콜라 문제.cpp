#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n>=a){
        int got = n/a*b;
        answer+=got;
        n = n%a + got;
    }
    
    return answer;
}