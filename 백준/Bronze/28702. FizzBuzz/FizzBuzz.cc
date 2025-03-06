#include <iostream>
using namespace std;

bool is_digit(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) continue;
		else return false;
	}
	return true;
}

void fizz(int k) {
	if (k % 3 == 0 && k % 5 == 0) {
		cout << "FizzBuzz";
	}
	else if (k % 3 == 0 && k % 5 != 0) cout << "Fizz";
	else if (k % 3 != 0 && k % 5 == 0) cout << "Buzz";
	else cout << k;
}

//입력 세개를 받고, 그걸로 다음번에 올걸 출력하는 것 -> 15를 주기로 하네!, 숫자가 꼭 있어야 됨.
//c++ 문자열 처리하는게 익숙하지 않음.
//반복문으로 처리하는거, 숫자인지 아닌지 확인하는 거, 문자로 받은 숫자에 int를 씌워도 정수가 되지 않는다는거 기억하지.
int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int key = 0;
	
	if (is_digit(s3)) {
		for (int i = 0; i < s3.length(); i++) {
			key += s3[i] - '0';
			
			key *= 10;
		}
		key /= 10;
		fizz(key + 1);
		

	}
	else {
		if (is_digit(s2)) {
			for (int i = 0; i < s2.length(); i++) {
				key += int(s2[i]) - '0';
				key *= 10;
			}
			key /= 10;
			fizz(key + 2);
		}


		else {
			for (int i = 0; i < s1.length(); i++) {
				key +=int(s1[i]) - '0';
				key *= 10;
			}
			key /= 10;
			fizz(key + 3);
		}
	}









}