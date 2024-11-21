#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>>vec(n);
	for (int i = 0; i < n; i++) {
		pair<int, int> cur;
		cin >> cur.first >> cur.second;
		vec[i] = cur;
	}


	
	vector<int>cnt(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool cm = false;
			bool kg = false;

			if (vec[i].first < vec[j].first) 
				cm = true;
				
			if (vec[i].second < vec[j].second) 
				kg = true;
				
			if (cm && kg) cnt[i]++;
		}
		cout << cnt[i] + 1 << ' ';
	}




}