#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int res = 0;
	int idx = 0; //*의 인덱스를 저장

	for (int i = 0; i < 13; i++) 
	{
		char c;
		cin >> c;
		

		

		//숫자인지 *인지 
		//순서가 짝수인지 홀수인지
		//맨마지막 숫자인지 아닌지
		
		
			if (c == '*') 
			{
				idx = i+1;
				//cout << "idx: " << idx << "\n";
			}
			else 
			{
				if ((i+1) % 2 == 0) 
				{
					res += 3 * (c - '0');
					//cout << "i: " << i <<" " << res << "\n";
				}
				else 
				{
					res += (c - '0');
					//cout << "i: " << i << " " << res << "\n";
				}
			}
		

		

	}
	if (idx % 2 == 0) {
		int num = (10 - res % 10)%10;
		for (int i = 0; i <= 9; i++) {
			if ((3 * i) % 10 == num) {
				cout << i;
				return 0;
			}
		}
	}
	else {
		cout << (10 - res % 10)%10;
	}

}