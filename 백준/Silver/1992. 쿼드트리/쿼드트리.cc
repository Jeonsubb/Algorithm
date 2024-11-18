#include <iostream>
#include <vector>
#include <algorithm>
char brd[70][70];


using namespace std;

vector<char>vec;

void quad(int n,int r,int c,int nr,int nc) {
	int unit = n / 2;
	bool isone = false;
	bool iszero = false;
	

	if (unit == 1) {
		
		for (int i = r; i < nr; i++) {
			for (int j = c; j < nc; j++) {
				if (brd[i][j] == '0') iszero = true;
				if (brd[i][j] == '1') isone = true;
			}
		}

		if (isone && !iszero) {
			
			vec.push_back('1');
		}
		else if (!isone && iszero) {
			
			vec.push_back('0');
		}
		else {
			vec.push_back('(');
			for (int i = r; i < nr; i++) {
				for (int j = c; j < nc; j++) {
					if (brd[i][j] == '0') {
						
						vec.push_back('0');
					}
					if (brd[i][j] == '1') {
						
						vec.push_back('1');
					}
				}
			}
			vec.push_back(')');
		}

		
		return;
	}
	else {
		
		for (int i = r; i < nr; i++) {
			for (int j = c; j < nc; j++) {
				if (brd[i][j] == '0') iszero = true;
				if (brd[i][j] == '1') isone = true;
			}
		}

		if (isone && !iszero) {
			
			vec.push_back('1');
			
		}
		else if (!isone && iszero) {
			
			vec.push_back('0');
			
		}
		else {
			vec.push_back('(');
			quad(unit, r, c, r + unit, c + unit);
			quad(unit, r, c+unit, r + unit, c + 2*unit);
			quad(unit, r+unit, c, r+2*unit, c + unit);
			quad(unit, r+unit, c+unit, r+2*unit, c + 2*unit);
			vec.push_back(')');
		}
		
	}

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			brd[i][j] = str[j];
		}
	}
	quad(n, 0, 0, n, n);

	for (char x : vec) cout << x;
}