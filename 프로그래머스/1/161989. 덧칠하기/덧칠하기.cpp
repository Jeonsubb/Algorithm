#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    vector<int> v(n,0);
    //칠해야 되는 곳 체크
    for(auto& a:section) v[a-1]=1;
    
    for(int i=0;i<n;i++){
        if(v[i]==1){
            int idx =i;
            for(int k=0;k<m;k++){
                if(idx<n){
                v[idx]=0;
                idx++;
                }
            }
            answer++;
        }
        else continue;
    }
    return answer;
}