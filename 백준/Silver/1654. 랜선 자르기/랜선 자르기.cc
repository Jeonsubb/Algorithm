#include <vector>
#include <iostream>
using namespace std;

bool cal(vector<long long>v,long long mid,int n) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i] / mid;
	}

	if (cnt >= n) return true;
	else return false;
}



long long binary_s(long long left, long long mid, long long right,int n, vector<long long>v) {
	if (left > right) return mid;
	
	//mid보다 최대값이 있을수 있다!
	if (cal(v, mid, n)) {

		return binary_s(mid + 1, (mid + right + 1) / 2, right, n, v);
	}
	//작다는 거... n보다 mid가 최대값보다 크다는 것
	else {
		return binary_s(left, (left + mid - 1) / 2, mid - 1, n, v);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);


	int k, n;
	cin >> k >> n;

	vector<long long>v(k);
	long long max = 0;
	for (int i = 0; i < k; i++) {
		
		cin >> v[i];
		if (max < v[i]) max = v[i];


	}

	long long mid = (max + 1) / 2;
	cout << binary_s(1, mid, max,n,v);



	//랜선 길이가 int MAX까지 가능하므로 자료형을 longlong으로!



	////밑에 코드처럼 1부터 어딘가까지를 검사하는 단항증가일때..... 이분탐색을 사용 가능하다!!!!!!!!
	
	//int m = 1;
	//while (1) {
	//	int cnt = 0;
	//	//cout << m << "\n";
	//	for (int i = 0; i < k; i++) {
	//		cnt += v[i] / m;
	//		
	//	}

	//	if (cnt >= n) {

	//		m++;
	//		continue;
	//	}

	//	

	//	else {
	//		cout << m - 1;
	//		return 0;
	//	}




	//}










}