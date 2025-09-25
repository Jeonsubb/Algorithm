#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b - c << "\n";
	string x, y,z;
	x = to_string(a);
	y = to_string(b);
	z = x + y;
	cout << stoi(z) - c;
}