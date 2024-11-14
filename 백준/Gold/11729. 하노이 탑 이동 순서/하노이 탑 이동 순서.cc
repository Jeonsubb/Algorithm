#include <iostream>
using namespace std;
int cnt = 0;
void hanoi(int n, int from, int to, int temp) {
	
	if (n == 1) {
		cout << from << " " << to << "\n";
		
	}
	else {
		hanoi(n - 1, from, temp, to);
		cout << from << " " << to << "\n";
		hanoi(n - 1, temp, to, from);
	}
}

void hanoi_cnt(int n, int from, int to, int temp) {

	if (n == 1) {
		cnt++;
	}
	else {
		hanoi_cnt(n - 1, from, temp, to);
		cnt++;
		hanoi_cnt(n - 1, temp, to, from);
	}
}


int main() {
	int n;
	cin >> n;
	hanoi_cnt(n, 1, 3, 2);
	cout << cnt << "\n";
	hanoi(n, 1, 3, 2);
}