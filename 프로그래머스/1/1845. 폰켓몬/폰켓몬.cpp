#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int,int>cnt;
    
    for(auto a:nums)cnt[a]++;
    int s = cnt.size();
    int k=nums.size()/2;
    
    if(s>=k) return k;
    else{
        return s;
    }
    
    
}