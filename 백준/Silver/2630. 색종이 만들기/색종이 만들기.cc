#include <iostream>
using namespace std;
int brd[150][150];
int wcnt = 0;
int bcnt = 0;

void cnttt(int n, int r, int c, int nr, int nc) {
	int unit = n / 2;
	bool isblue = false;
	bool iswhite = false;
	if (unit == 1) {
		for (int i = r; i < nr; i++) {
			for (int j = c; j < nc; j++) {
				if (brd[i][j] == 1) isblue = true;
				if (brd[i][j] == 0) iswhite = true;
			}
		}
		if (isblue && !iswhite) bcnt++;
		else if (!isblue && iswhite) wcnt++;
		else {
			for (int i = r; i < nr; i++) {
				for (int j = c; j < nc; j++) {
					if (brd[i][j] == 1) bcnt++;
					if (brd[i][j] == 0) wcnt++;
				}
			}

		}
		return;
	}

	else {
		for (int i = r; i < nr; i++) {
			for (int j = c; j < nc; j++) {
				if (brd[i][j] == 1) isblue = true;
				if (brd[i][j] == 0) iswhite = true;
			}
		}
		if (isblue && !iswhite) bcnt++;
		else if (!isblue && iswhite) wcnt++;
		else {
			cnttt(unit, r, c, r + unit, c + unit);
			cnttt(unit, r, c + unit, r + unit, c + 2 * unit);
			cnttt(unit, r + unit, c, r + 2*unit, c + unit);
			cnttt(unit, r + unit, c + unit, r + 2*unit, c + 2 * unit);

		}
	}
}



int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> brd[i][j];
	}
	cnttt(n, 0, 0, n, n);
	cout << wcnt << "\n" << bcnt;

}