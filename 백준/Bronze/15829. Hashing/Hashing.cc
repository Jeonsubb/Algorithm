#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int l;
    cin >> l;

    long long res = 0;
    long long r = 1; // 31의 거듭제곱을 저장할 변수 (초기값 31^0 = 1)
    long long M = 1234567891;

    for (int i = 0; i < l; i++)
    {
        char c;
        cin >> c;
        int n = c - 'a' + 1;

        // n * (31^i) 항을 계산하고 바로 모듈러 연산
        // (n * r)이 long long 범위를 넘을 수 있으므로 각각 long long으로 변환
        long long term = (static_cast<long long>(n) * r) % M;

        // 결과에 더하고 다시 모듈러 연산
        res = (res + term) % M;

        // 다음 루프에서 사용할 31의 거듭제곱 값을 갱신
        r = (r * 31) % M;
    }

    cout << res;

    return 0;

}