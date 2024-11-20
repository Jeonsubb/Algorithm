#include <iostream>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;
void func(int k, int sum) {
	if (k == n) {
		if (sum == s) cnt++;
		return;
	}
	func(k + 1, sum); //더하지 않은채로 재귀
	func(k + 1, sum + arr[k]);//더한채로 재귀
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	func(0, 0);
	if (s == 0) cnt--; //공집합은 제외하니까
	cout << cnt;
}