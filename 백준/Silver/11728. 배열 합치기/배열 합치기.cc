#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int>a;
	vector<int>b;
	vector<int>c;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		b.push_back(n);
	}

	sort(a.begin(), a.end());

	sort(b.begin(), b.end());

	int aidx = 0;
	int bidx = 0;
	
	while (aidx != n || bidx != m) {
		if (aidx != n && bidx!=m) {
			if (a[aidx] <= b[bidx]) {
				c.push_back(a[aidx]);
				aidx += 1;
			}
			else {
				c.push_back(b[bidx]);
				bidx += 1;
			}
		}
		else {
			if (aidx == n) {
				c.push_back(b[bidx]);
				bidx++;
			}
			else {
				c.push_back(a[aidx]);
				aidx++;
			}
		}
	}

	for (auto a : c)cout << a << " ";


}