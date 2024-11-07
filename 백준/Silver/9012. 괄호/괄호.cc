#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char>s;
		bool isbreak=false;
		string str;
		cin >> str;
		for (char x : str) {
			if (x == '(') s.push(x);
			//괄호 쌍이 들어올 때 ) 얘가 먼저 들어오는 상황
			//스택이 비었는데 먼저 들어오는 상황에서는 NO임
			else if (x == ')') {
				if (!s.empty()) s.pop();
				//스택이 비어있을 때 상황
				else {
					isbreak = true;
					break;
				}
			}
		}

		if (!isbreak && s.empty()) cout << "YES" << '\n';
		//break 상황 혹은 비어있지 않은 상황
		else if (isbreak || !s.empty()) cout << "NO" << '\n';
	}


}