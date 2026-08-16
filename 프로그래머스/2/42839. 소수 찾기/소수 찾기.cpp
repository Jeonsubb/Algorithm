#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void dfs(const string& numbers, vector<bool>& used, string cur, set<int>& nums) {
    if (!cur.empty()) nums.insert(stoi(cur));

    for (int i = 0; i < (int)numbers.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        dfs(numbers, used, cur + numbers[i], nums);
        used[i] = false;
    }
}

int solution(string numbers) {
    set<int> nums;
    vector<bool> used(numbers.size(), false);
    dfs(numbers, used, "", nums);

    int answer = 0;
    for (int n : nums)
        if (isPrime(n)) answer++;

    return answer;
}