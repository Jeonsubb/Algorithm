#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	int l;
	cin >> l;
	int res = 0;

	for (int i = 0; i < l; i++) 
	{
		char c;
		cin >> c;
		int n = c - 'a' + 1;
		int tmp= (n * pow(31, i));
		res += tmp % 1234567891;

	}

	cout << res;

}