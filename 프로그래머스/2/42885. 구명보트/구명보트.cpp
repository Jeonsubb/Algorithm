#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    
    //정렬 하고
    sort(people.begin(), people.end());

    int answer = 0;
    
    //처음 인덱스가 제일 가벼움
    int light = 0;
    
    //끝 인덱스가 제일 무거움
    int heavy = people.size() - 1;

    //끝과 끝에서 시작해서 다 빼면 하나만 남을테니깐
    while (light <= heavy) {
        // 가장 무거운 사람과 가장 가벼운 사람이 함께 탈 수 있는 경우, 그래서 태우고 나면 다음 가벼운 사람으로.
        if (light < heavy &&
            people[light] + people[heavy] <= limit) {
            light++;
        }

        // 가장 무거운 사람은 항상 이번 보트에 탑승
        heavy--;
        answer++;
    }

    return answer;
}