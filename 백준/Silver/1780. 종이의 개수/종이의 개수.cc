#include<iostream>
using namespace std;
int brd[2500][2500];
int cnt0 = 0;
int cnt1 = 0;
int cnt2 = 0;
void cnt(int n,int r,int c,int nr,int nc) {
	int unit = n / 3;
	

	bool isz = false;
	bool iso = false;
	bool ist = false;

	//base condition!
	if (unit == 1) {
		for (int i = r; i < nr; i++) {
			for (int j = c; j < nc; j++) {
				if (brd[i][j] == -1)  isz = true;
				else if (brd[i][j] == 0) iso = true;
				else if (brd[i][j] == 1) ist = true;
			}
		}
		if (isz && !iso && !ist) cnt0++;
		else if (!isz && iso && !ist) cnt1++;
		else if (!isz && !iso && ist) cnt2++;

		else {
			for (int i = r; i < nr; i++) {
				for (int j = c; j < nc; j++) {
					if (brd[i][j] == -1)cnt0++;
					if (brd[i][j] == 0)cnt1++;
					if (brd[i][j] == 1)cnt2++;
				}
			}
		}
		return ;
	}
	//반복..
	else {
		for (int i = r; i < nr; i++) {
			for (int j = c; j < nc; j++) {
				if (brd[i][j] == -1)  isz = true;
				else if (brd[i][j] == 0) iso = true;
				else if (brd[i][j] == 1) ist = true;
			}
		}

		if (isz && !iso && !ist) cnt0++;
		else if (!isz && iso && !ist) cnt1++;
		else if (!isz && !iso && ist) cnt2++;
		else {
			cnt(unit, r, c,r+unit,c+unit); //첫번째
			cnt(unit, r, c+unit, r + unit, c + 2*unit); //두번째
			cnt(unit, r, c+2*unit, r + unit, c + 3 * unit); //세번째
			cnt(unit, r+unit, c, r + 2*unit, c + unit); //네번째
			cnt(unit, r+unit, c+unit, r + 2 * unit, c + 2*unit); //5번째
			cnt(unit, r+unit, c+2*unit, r + 2 * unit, c +3* unit); //6번째
			cnt(unit, r+2*unit, c, r + 3 * unit, c + unit); //7번째
			cnt(unit, r+2 * unit, c+unit, r + 3 * unit, c + 2*unit); //8번째
			cnt(unit, r+ 2 * unit, c+2*unit, r + 3 * unit, c + 3* unit); //9번째

		
		}
		
	}

}

int main() {
	int n; 
	//n은 n*n 크기의 행렬을 만들 것임
	//n은 3의 거듭제곱임
	cin >> n;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) cin >> brd[r][c];
	}

	cnt(n, 0, 0, n, n);

	cout << cnt0 << "\n";
	cout << cnt1 << "\n";
	cout << cnt2 << "\n";
}