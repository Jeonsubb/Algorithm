#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//sort 정렬 함수에 내가 정의한 비교 함수를 넣을 수 있도록 하자가 중요
bool cmp(string& a,string& b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    vector<string> s;
    //미리 공간 확보
    s.reserve(numbers.size());
    //각 숫자 문자열로 받아 넎기
    for (int n : numbers) s.push_back(to_string(n));
    //정렬
    sort(s.begin(), s.end(), cmp);

    if (s[0] == "0") return "0";   // 전부 0인 경우

    string answer;
    for (const string& x : s) answer += x;
    return answer;
}