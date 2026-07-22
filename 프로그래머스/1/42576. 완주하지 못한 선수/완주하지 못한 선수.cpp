#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string,int> count;
    for (auto& name:participant) count[name]++;
    for(auto& name:completion ) count[name]--;
    
    for(auto& name:participant ){
        if(count[name]>0) return name;
    }

    
    //return answer;
}