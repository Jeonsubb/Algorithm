#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    int k=0;
    for(auto& c:s)
    {
        
        while(k!=index)
        {
            c++;
            if(c>'z') c='a';
            
            //skip에 포함이 안됨
            if(find(skip.begin(),skip.end(),c)==skip.end())
            {
                k++;
            }
            //skip에 포함됨
            else
            {
                continue;
            }
        }
        k=0;
        answer+=c;
    }
    return answer;
}