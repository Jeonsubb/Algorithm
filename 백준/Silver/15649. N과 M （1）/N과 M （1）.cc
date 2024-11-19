#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//1차 시도---> 마스크 두고 할려했는데 순열을 어떻게 표현하지..? 하는 문제에 봉착
//int main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//
//	int n, m;
//	cin >> n >> m;
//	vector<int>vec1;
//	vector<int>mask(n);
//
//	for (int i = 1; i <= n; i++) vec1.push_back(i);
//	int i = 1;
//	int j = 0;
//	while (i != m) {
//		
//		fill(mask.begin()+j, mask.begin() + i, i);
//		i++;
//		j++;
//	}
//	do {
//		for (int i = 0; i < n; i++) {
//			if (mask[i] != 0) cout << vec1[i] << " ";
//		}
//		cout << "\n";
//	} while (prev_permutation(mask.begin(), mask.end()));
//}

int n, m;
int arr[10];
bool isused[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	func(0);
}