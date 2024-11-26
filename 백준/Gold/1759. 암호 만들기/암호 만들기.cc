#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char arr[20];
bool isused[20];
int l, c;

void func(int n,vector<char>vec,int cnt1,int cnt2) {
	if (n == l) {
		if (cnt1 >= 1 && cnt2 >= 2) {
			for (int i = 0; i < l; i++) cout << arr[i];
			cout << '\n';
			return;
		}
		else return;
	}
	for (int i = 0; i < c; i++) {
		if (!isused[i]) {
			//뒤에 오는게 사전순으로 커야하니깐
			if (n == 0 || arr[n - 1] < vec[i]) {
				bool is1 = false;
				
				arr[n] = vec[i];
				isused[i] = 1;
				
				if (vec[i] == 'a' || vec[i] == 'i' || vec[i] == 'e' || vec[i] == 'o' || vec[i] == 'u') {
					cnt1++;
					is1 = true;
				}
				else cnt2++;
				func(n + 1, vec,cnt1,cnt2);
				isused[i] = 0;
				//재귀호출 전으로 돌려줘야 됨!!!!

				if (is1) cnt1--;
				else cnt2--;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> l >> c;
	vector<char>vec(c);
	for (int i = 0; i < c; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	func(0, vec,0,0);
}