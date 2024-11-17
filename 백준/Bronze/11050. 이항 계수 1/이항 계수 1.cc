#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {

	
	int n, k;
	cin >> n >> k;
	vector<int>vec(n);
	//fill(vec.begin(), vec.begin() + n, 0);
	fill(vec.begin(), vec.begin() + k, 1);
	int cnt = 0;
	do {
		cnt++;
	} while (prev_permutation(vec.begin(), vec.end()));

	cout << cnt << endl;





}

