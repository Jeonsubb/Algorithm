#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10];
int n, m;

void func(int k, vector<int>vec) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[k] = vec[i];
		func(k + 1, vec);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int>vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	func(0, vec);

}