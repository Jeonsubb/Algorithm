#include <iostream>
using namespace std;

int n, k;
int a[15];


//그리디라고 하지만 사실은 그리디가 아닌듯한...

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		ans += k / a[i];
		k %= a[i];
	}

	cout << ans;
}