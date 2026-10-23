#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    //운행 횟수, 최대 인원, 일행 수
    int r,k,n;

    cin >> r >> k >>n;
    queue<int> q;

    long long answer=0;

    //일행 수만큼 각 일행 숫자 받기
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        q.push(a);
    }

    //r번의 운행 시작
    for(int i=0;i<r;i++){
        int sum=0;
        int cnt=0;
        while(1){
            int cur = q.front();
            cnt++;
            sum+=cur;
            if(sum<=k && cnt<=n) {
                q.push(cur);
                q.pop();
            }
            else {
                sum-=cur;
                break;
            }
        }

        answer+=sum;
    }

    cout << answer;
}
