#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string rever = "";
    for(int i=1;i<food.size();i++){
        int n = food[i] / 2;
        for(int j=0;j<n;j++){
            answer += to_string(i);
            rever += to_string(i);
        }
    }
    answer+="0";
    
    reverse(rever.begin(),rever.end());
    answer+=rever;
    
    
    
    return answer;
}