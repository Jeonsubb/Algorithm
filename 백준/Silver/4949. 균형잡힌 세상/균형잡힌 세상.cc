#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (1) {
		stack<char>s; //매번 새로운 문장으로 스택을 구성해야 되니까 초기화 해줘야 됨!
		string str;
		bool isbreak = false;
		getline(cin,str);


		if (str == ".") break; //종료조건

		//문장의 문자들 추출
		for (char x : str) {
			if (x == '[' || x == '(') {
				s.push(x);
			}
			else if (x == ']') {
				if (!s.empty() && s.top() == '[')s.pop();
				else {
					
					isbreak = true;
					break;
				}
			}
			else if (x == ')') {
				if (!s.empty() && s.top() == '(')s.pop();
				else {
					
					isbreak = true;
					break;
				}
			}
			else continue;

		}
		

		if (!isbreak &&s.empty()) cout << "yes" << "\n";
		else {
			cout << "no" << "\n";
		}

	}
}