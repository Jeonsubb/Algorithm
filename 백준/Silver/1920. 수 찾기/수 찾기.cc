#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int func(const vector<int>& v, int a, int s, int e) {
	if (s > e) return 0; // 탐색 범위가 역전되면 종료

	int m = (s + e) / 2;

	if (v[m] == a) return 1; // 값을 찾았으면 1 반환
	else if (v[m] < a) return func(v, a, m + 1, e); // 오른쪽 탐색 가운데가 아닌건 확실하니깐.
	else return func(v, a, s, m - 1); // 왼쪽 탐색
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	vector<int>v;

	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	int m;
	cin >> m;

	sort(v.begin(), v.end());

	int mid = (n-1) / 2;
	

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		
		/*auto it = find(v.begin(), v.end(), n);
		if (it != v.end()) cout << 1 << "\n";
		else cout << 0 << "\n";*/

		if (func(v, num, 0, n - 1) == 1) cout << 1 << "\n";
		else cout << 0 << "\n";

	}

}