//숫자가 너무 커지기 때문에 나머지만 가져가는 방식으로 생각해야 됨.
//a를 b번 곱하는 방식으로는 시간 초과가 발생함
//그래서 2의 제곱승으로 커지도록 만든다...?
#include <iostream>
using namespace std;
using ll = long long;

ll mul(ll a, ll b, ll c) {
	if (b == 1) return a % c; //b가 1일때가 base condition임.

	ll val = mul(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) return val;
	return val * a % c;
	
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a, b, c;
	cin >> a >> b >> c;
	cout << mul(a, b, c);
}



//1승을 계산할 수 있다
//k승을 계산했으면 2k승과 2k+1승도 O(1)에 계산할 수 있다.

