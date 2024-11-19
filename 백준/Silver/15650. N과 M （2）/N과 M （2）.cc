#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void nm(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			if (k == 0 || arr[k - 1] < i) {
				arr[k] = i;
				isused[i] = 1;
				nm(k + 1);
				isused[i] = 0;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	nm(0);
}