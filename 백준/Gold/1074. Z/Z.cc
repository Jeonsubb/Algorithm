
//1차 시도 -> 이차원 배열로 거리를 계산하면서 접근한다고 생각...
//문제에서 제시하고 있는 최대값으로 배열을 잡아버린다면
//4기가바이트의 배열이 필요 -> 말도 안되는 크기임.

//#include <iostream>
//#include <algorithm>
//using namespace std;
////4의 배수..
////행을 기준으로 2의 n승의 절반보다 r이 작다면..?
////00 01 10 11 
////n이라면 n-1이 네개가 있는 것!
////base는 n=1일때 그려지는 2*2임.
//int bored[30000][30000];
////r,c는 출발행,출발열
//void z(int n, int r, int c,int dis) {
//	int n2 = 1 << n;
//	int area_unit = (n2 / 2) * (n2 / 2);
//	if (n == 1) {
//		bored[r][c] = dis;
//		bored[r][c + 1] = dis + 1;
//		bored[r+1][c] = dis+2;
//		bored[r+1][c + 1] = dis + 3;
//		return;
//	}
//	// 0 0
//	z(n - 1, r, c,dis);
//	// 0 1
//	z(n - 1, r, c+ n2/2,dis+ area_unit);
//	//1 0
//	z(n - 1, r + n2 / 2, c,dis+ area_unit *2);
//	//1 1
//	z(n - 1, r+n2/2, c+ n2/2,dis+ area_unit *3);
//	
//}
//
//
//int main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int n,r,c;
//	cin >> n>>r>>c;
//
//	//시작
//	z(n, 0, 0, 0);
//
//	cout << bored[r][c];
//
//
//
//}



#include <iostream>
using namespace std;

int z(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1); // 한 변의 길이를 반으로 나눔
    int area_unit = half * half;

    if (r < half && c < half) {
        // 0, 0 (왼쪽 위)
        return z(n - 1, r, c);
    }
    else if (r < half && c >= half) {
        // 0, 1 (오른쪽 위)
        return area_unit + z(n - 1, r, c - half);
    }
    else if (r >= half && c < half) {
        // 1, 0 (왼쪽 아래)
        return 2 * area_unit + z(n - 1, r - half, c);
    }
    else {
        // 1, 1 (오른쪽 아래)
        return 3 * area_unit + z(n - 1, r - half, c - half);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, r, c;
    cin >> n >> r >> c;

    cout << z(n, r, c) << endl;

    return 0;
}
