#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[10];

bool isused[10];


void func(int k,vector<int> vec) {
	//base condition
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[k] = vec[i];
			isused[i] = 1;
			func(k + 1,vec);
			isused[i] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	//배열 초기화
	vector<int>vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	func(0,vec);


}