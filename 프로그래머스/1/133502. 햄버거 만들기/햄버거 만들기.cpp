#include <string>
#include <vector>

using namespace std;



int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;
    for(int i:ingredient){
        v.push_back(i);
        int n=v.size();
        
        if(n>=4&&v[n-4]==1&&v[n-3]==2&&v[n-2]==3&&v[n-1]==1){
            v.resize(n-4); //4개만큼을 없애버리는것
            answer++;
        }
    }
    return answer;
}