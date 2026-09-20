#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;

    for (int a = 1; a <= n - 4; ++a) {
        for (int b = a + 1; b <= n - 3; ++b) {
            for (int c = b + 1; c <= n - 2; ++c) {
                for (int d = c + 1; d <= n - 1; ++d) {
                    for (int e = d + 1; e <= n; ++e) {
                        int code[5] = {a, b, c, d, e};
                        bool possible = true;

                        for (int i = 0; i < static_cast<int>(q.size()); ++i) {
                            int matched = 0;

                            for (int number : q[i]) {
                                matched += binary_search(code, code + 5, number);
                            }

                            if (matched != ans[i]) {
                                possible = false;
                                break;
                            }
                        }

                        answer += possible;
                    }
                }
            }
        }
    }

    return answer;
}
