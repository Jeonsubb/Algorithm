#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10];
bool isused[10];
int n, m;

void func(int k, vector<int>vec) {
	if (k == m) {
		for(int i=0;i<m;i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int last = -1; 
	for (int i = 0; i < n; i++) {
		if ((!isused[i] && last != vec[i])) {
			if (k == 0 || arr[k - 1] <= vec[i]) {
				arr[k] = vec[i];
				isused[i] = 1;
				last = vec[i];
				func(k + 1, vec);
				isused[i] = 0;
			}
		}
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