#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b)<<'\n'<<lcm(a,b);



}