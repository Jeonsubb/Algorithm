#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10];
bool isused[10];
//bool ise[10];
int n, m;

void func(int k, vector<int>vec) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int last = -1;//이전에 사용한 값을 기록

	for (int i = 0; i < n; i++) {
		if (!isused[i]&&vec[i]!=last) {

			arr[k] = vec[i];

			
			isused[i] = 1;

			last = vec[i]; //얘가 딱 전 값만 기록해서 가능하네 -> 즉 같은 수열을 만들 수 없음.

			//백트레킹 방식이 지금 여기서 for문 돌면서 해당하는 값들이 그 뒤에 붙는 건데.....
			//뒤에 붙을 때 이전의 값이 또 나오면 생략하는거니깐 가능한거지!
			func(k + 1, vec);

	
			isused[i] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int>vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());
	func(0, vec);

}