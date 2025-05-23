#include <string>
#include <vector>

using namespace std;

int arr[101][101];              // 택버 번호를 담을 배열
int chk[101];                   // 각 행당 어디까지를 넣었는지 체크
int solution(int n, int w, int num) {
    int answer = 0;
    //vector<pair<int,int>>v;
    int count = 0;              //돌면서 w가 되면 0으로 초기화 됨
    
    
 
    int nc=1;                  //넣을 택배 번호
    int dx = 1;                 // 방향 조정
    int num_ridx = 0;            //찾고 싶은 친구의 행
    int num_cidx=0;             //찾고 싶은 친구의 열
    
    for(int i=1;i<=n;i++){
        
        if(i%w!=0){             
        arr[count][chk[count]]=nc;   
        nc++;                   // 택배 번호 증가
            chk[count]++;               // 열 인덱스 증가
        count += dx;                // 행 이동
        
        }
        else {
            if((i/w)%2==1) {
                arr[count][chk[count]]=nc;   
                nc++;                   // 택배 번호 증가
                //count += dx;                // 행 이동
                //위로 올라가는 느낌이기에 행 이동을 안해도 됨
                chk[count]++;               // 열 인덱스 증가
                dx=-1;   //홀수 칸 다음에 쌓을 때는 오른쪽에서 왼쪽으로 이동   
            }
            else {
                
                arr[count][chk[count]]=nc;   
                nc++;                   // 택배 번호 증가
                //count += dx;                // 행 이동
                //위로 올라가는 느낌이기에 행 이동을 안해도 됨
                chk[count]++;               // 열 인덱스 증가
                
                
                
                dx=1; //짝수 칸 다음에 쌓을 때는 왼쪽에서 오른쪽으로 이동
                 
                 
                 
                 }             
        }
            
        if(nc==num){            // 내가 찾고 싶은 친구 등장
            num_ridx=count;
            num_cidx=chk[count];
        }
       
        
    }
    
   answer=chk[num_ridx]-num_cidx;       //찾고 싶은 친구일 떄 저장한 열 개수만큼을 나중의 열 개수에서 빼면 됨 그리고 자신도 빼는 거니깐 +
    
    
    return answer;
}