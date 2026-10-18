#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n = p.size();
    int st=0;
    int end = n-1;
    
    long long k = stoll(p);
    
    while(end < t.size()){
        cout << "st:" << st << "end:" << end;
        long long cur = stoll(t.substr(st,n));
        st++;
        end++;
        if(cur<=k) answer++;
    }
    return answer;
}