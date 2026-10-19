#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end());
    int n = score.size() % m;
    //cout << n << "\n";
    
    for(int i=n;i<score.size();i++){
        vector<int> v(m,0);
        for(int j=0;j<m;j++){
            v[j] = score[i];
            //cout <<"i:" << i <<"\n";
            i++;
        }
        i--;
        //cout << *min_element(v.begin(),v.end()) << "\n";
        answer+= *min_element(v.begin(),v.end()) * m;
    }
    return answer;
}