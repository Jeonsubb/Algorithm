#include <iostream>
using namespace std;

int countTrailingZeros(int n) {
    int count = 0;
    for (int i = 5; i <= n; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    cout << countTrailingZeros(n) << '\n';

    return 0;
}
