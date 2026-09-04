#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();

    // (도착시각, 소요시간, 번호) 로 만들어서 도착 순 정렬
    vector<tuple<int,int,int>> arr;
    for (int i = 0; i < n; i++)
        arr.push_back({jobs[i][0], jobs[i][1], i});
    sort(arr.begin(), arr.end());

    // 힙 기준: (소요시간, 도착시각, 번호) 오름차순
    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<>> pq;

    long long now = 0, total = 0;
    int i = 0, done = 0;

    while (done < n) {
        // 지금까지 도착한 작업 전부 대기 큐에 투입
        while (i < n && get<0>(arr[i]) <= now) {
            pq.push({get<1>(arr[i]), get<0>(arr[i]), get<2>(arr[i])});
            i++;
        }

        if (pq.empty()) {          // 아무도 대기 중이 아니면 시간 점프
            now = get<0>(arr[i]);
            continue;
        }

        auto [dur, start, idx] = pq.top();
        pq.pop();
        now += dur;                // 이 작업이 끝나는 시각
        total += now - start;      // 반환 시간 = 종료 - 요청
        done++;
    }

    return total / n;
}