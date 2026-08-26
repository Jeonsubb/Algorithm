#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;

    // 1) 상하 조작
    for (int i = 0; i < n; i++)
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

    // 2) 좌우 조작
    int move = n - 1;                    // 오른쪽으로 쭉 미는 경우
    for (int i = 0; i < n; i++) {
        int next = i + 1;
        while (next < n && name[next] == 'A') next++;   // A 구간 건너뛰기

        move = min(move, i * 2 + (n - next));           // 오른쪽 갔다 되돌아오기
        move = min(move, (n - next) * 2 + i);           // 왼쪽 갔다 되돌아오기
    }

    return answer + move;
}