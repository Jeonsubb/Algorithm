#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    vector<string> w = {"aya", "ye", "woo", "ma"};
    int answer = 0;

    for (auto& s : babbling) {
        int i = 0, prev = -1;
        bool ok = true;

        while (i < s.size()) {
            int found = -1;
            for (int j = 0; j < 4; j++) {
                if (s.compare(i, w[j].size(), w[j]) == 0) { found = j; break; }
            }
            if (found == -1 || found == prev) { ok = false; break; }
            i += w[found].size();
            prev = found;
        }
        if (ok) answer++;
    }
    return answer;
}