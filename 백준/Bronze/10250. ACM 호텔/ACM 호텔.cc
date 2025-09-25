#include <iostream>
#include <string>
using namespace std;
int t, h, w, n;
int main() {
	cin >> t;
	while (t--) 
	{
		cin >> h >> w >> n;
		for (int i = 1; i <= w; i++) 
		{
			for (int j = 1; j <= h; j++) 
			{
				n--;
				if (n == 0) 
				{
					string x, y, z;
					x = to_string(j);
					y = to_string(i);
					if (y.size() == 1)
					{
						z = x + "0" + y;
						cout << z << "\n";
						break;
					}
					else 
					{
						z = x + y;
						cout << z << "\n";
						break;
					}
				}
			}
		}
	}
	return 0;
}