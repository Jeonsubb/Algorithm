#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	queue<int>Q;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		
		Q.push(i);
	}

	while (Q.size() != 1) {
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}

	cout << Q.front();




}