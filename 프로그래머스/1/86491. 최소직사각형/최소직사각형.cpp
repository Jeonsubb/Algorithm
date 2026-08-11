#include <string>
#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int>& v){
    if(v[0]>v[1]) return;
    else{
        int temp = v[0];
        v[0]=v[1];
        v[1] = temp;
    }
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    //모든 배열들을 0 1 중에 0을 큰값, 1에 작은 값 두고 0중에서 max, 1중에서 max
    int max_0 = 0;
    int max_1 =0;
    for(auto& a: sizes){
        swap(a);
        cout << a[0] <<" " << a[1] << "\n";
        if(max_0<a[0]) max_0=a[0];
        if(max_1<a[1]) max_1 = a[1];
    }
    
    answer = max_0*max_1;
    
    return answer;
}