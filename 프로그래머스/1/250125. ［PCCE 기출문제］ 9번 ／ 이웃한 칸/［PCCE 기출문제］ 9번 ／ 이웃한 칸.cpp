#include <string>
#include <vector>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    //가로, 세로 길이
    int n = board.size();
    
    string color = board[h][w];
    
    for(int i=0;i<4;i++){
        int nxtx = dx[i]+w;
        int nxty = dy[i]+h;
        if(nxtx<0 || nxtx>n-1||nxty<0 || nxty>n-1) continue;
        if(board[nxty][nxtx] == color) answer++;
    }
    return answer;
}