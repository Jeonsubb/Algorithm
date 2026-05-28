#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Word {
    string text;
    int start;
    int end;
};

bool isOverlap(int aStart, int aEnd, int bStart, int bEnd) {
    return !(aEnd < bStart || bEnd < aStart);
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    vector<Word> words;

    int n = message.size();

    // 1. 단어와 단어의 시작/끝 인덱스 저장
    int i = 0;
    while (i < n) {
        int start = i;
        string text = "";

        while (i < n && message[i] != ' ') {
            text += message[i];
            i++;
        }

        int end = i - 1;
        words.push_back({text, start, end});

        i++; // 공백 건너뛰기
    }

    int wordCount = words.size();

    vector<bool> isSpoilerWord(wordCount, false);

    // 2. 각 단어가 스포 구간과 겹치는지 체크
    for (int w = 0; w < wordCount; w++) {
        for (auto range : spoiler_ranges) {
            int rs = range[0];
            int re = range[1];

            if (isOverlap(words[w].start, words[w].end, rs, re)) {
                isSpoilerWord[w] = true;
                break;
            }
        }
    }

    // 3. 일반 구간에 등장한 단어 저장
    set<string> normalWords;

    for (int w = 0; w < wordCount; w++) {
        if (!isSpoilerWord[w]) {
            normalWords.insert(words[w].text);
        }
    }

    set<string> revealedSpoilerWords;
    int answer = 0;

    // 4. 스포 구간을 왼쪽부터 클릭
    for (auto range : spoiler_ranges) {
        int rs = range[0];
        int re = range[1];

        // 이 구간과 겹치는 단어들을 왼쪽부터 확인
        for (int w = 0; w < wordCount; w++) {
            if (!isOverlap(words[w].start, words[w].end, rs, re)) {
                continue;
            }

            string cur = words[w].text;

            // 일반 구간에 등장한 적 있으면 중요 단어 아님
            if (normalWords.count(cur)) {
                continue;
            }

            // 이전에 공개된 스포 단어와 중복이면 중요 단어 아님
            if (revealedSpoilerWords.count(cur)) {
                continue;
            }

            revealedSpoilerWords.insert(cur);
            answer++;
        }
    }

    return answer;
}