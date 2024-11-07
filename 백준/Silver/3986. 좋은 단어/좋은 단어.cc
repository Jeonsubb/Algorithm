#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int cnt = 0; //좋은 단어인지 세는 것
	for (int i = 0; i < n; i++) {
		stack<char>s;
		string str;
		cin >> str;

		for (int x : str) {
			//좋은 단어일려면 스택 안에 문자가 있을 때 같은 문자라면 
			//pop, 다른 문자라면 push를 진행
			if (x == 'A') {
				//비었다면 일단 푸시
				if (s.empty())s.push(x);
				//비어있지 않을 때 처리
				else {
					//A라면 pop처리
					if (s.top() == 'A') s.pop();
					//A가 아니라면 push
					else s.push(x);

				}
			}
			//B일 때 처리
			else {
				//비었다면 일단 푸시
				if (s.empty())s.push(x);

				//비어있지 않을 때 처리
				else {
					//B라면 pop처리
					if (s.top() == 'B') s.pop();
					//B가 아니라면 push
					else s.push(x);

				}
			}

		}

		//스택이 비었다면 좋은 단어임
		if (s.empty()) cnt++;


	}
	cout << cnt;




}