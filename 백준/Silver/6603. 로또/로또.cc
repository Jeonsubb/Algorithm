#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[15];
bool isused[15];
int k;

void func(int n,vector<int>vec) {
	if (n == 6) {
		for (int i = 0; i < 6; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return; //리턴추가하자!
	}
	for (int i = 0; i < k; i++) {
		if (!isused[i]) {
			if (n == 0 || arr[n - 1] < vec[i]) {
				arr[n] = vec[i]; //n과 i를 구분하자!
				isused[i] = 1;
				func(n + 1, vec);
				isused[i] = 0;
			}
		}
	}
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> k;
	while (k != 0) {
		vector<int>vec(k);
		for (int i = 0; i < k; i++) cin >> vec[i];
		func(0, vec);
		cout << '\n';
		cin >> k;
	}


}