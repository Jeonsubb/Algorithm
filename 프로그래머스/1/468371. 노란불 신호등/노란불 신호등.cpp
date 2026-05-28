#include <string>
#include <vector>
#include <numeric>

using namespace std;

long long gcd_ll(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm_ll(long long a, long long b) {
    return a / gcd_ll(a, b) * b;
}

int solution(vector<vector<int>> signals) {
    long long limit = 1;

    // 전체 상태가 반복되는 주기 계산
    for (auto &s : signals) {
        int G = s[0];
        int Y = s[1];
        int R = s[2];

        int period = G + Y + R;
        limit = lcm_ll(limit, period);
    }

    // 1초부터 전체 반복 주기까지 확인
    for (long long t = 1; t <= limit; t++) {
        bool allYellow = true;

        for (auto &s : signals) {
            int G = s[0];
            int Y = s[1];
            int R = s[2];

            int period = G + Y + R;
            int pos = (t - 1) % period;

            if (!(G <= pos && pos < G + Y)) {
                allYellow = false;
                break;
            }
        }

        if (allYellow) {
            return (int)t;
        }
    }

    return -1;
}