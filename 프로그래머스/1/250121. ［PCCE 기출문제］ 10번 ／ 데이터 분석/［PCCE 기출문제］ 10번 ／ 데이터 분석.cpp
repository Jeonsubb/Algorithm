#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int m;
bool cmp(vector<int>& a,vector<int>& b){
    return a[m]<b[m];
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int n;
    if(ext=="code") n=0;
    else if(ext=="date") n=1;
    else if(ext=="maximum") n=2;
    else if(ext=="remain") n=3;
    
    for(int i=0;i<data.size();i++){
        if(data[i][n] < val_ext) answer.push_back(data[i]);
    }
    
    
    if(sort_by=="code") m=0;
    else if(sort_by=="date") m=1;
    else if(sort_by=="maximum") m=2;
    else if(sort_by=="remain") m=3;
    
    sort(answer.begin(),answer.end(),cmp);
    
    
    return answer;
}