#include <iostream>
#include <stack>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int sum = 0;
	string str;
	cin >> str;

	stack<pair<char, int>>s;
	bool isbreak = false;
	
	

	//괄호 안에 괄호가 있을 때 어떻게 처리를 하지...
	//스택 안에 괄호가 아직 있는데 다르 괄호가 닫혔을 때
	//스택 안에 괄호가 없고 닫혔을 때
	//인덱스를 저장하지 말고 값을 저장
	//일단 푸시하면 0을 같이 넣어
	//다른 괄호 쌍이 닫히면 pop하고 남은 괄호의 second에 더하거나 곱해
	//() 얘네를 어째 구분하냐 -> second가 0이면 방금 들어온 놈


	for (int i = 0; i < str.length(); i++) {
		int num = 0;

		if (str[i] == '(' || str[i] == '[') {
			s.push({ str[i] ,0 }); //일단 0을 다 넣어
		}

		else if (str[i] == ')') {
			//닫는 괄호 시 스택 비어있는지 확인
			if (s.empty() || s.top().first != '(') {
				isbreak = true;
				break;
			}
			//시작하자마자 이렇게 해당하지 않는 친구들 죽이니까 밑에
			//코드에 '(' 인지 확인 안 해도 됨.



			if (s.top().second == 0) { //0이라면 () 이거나 [] 이거처럼 바로 나온거임

				s.pop(); //일단 날려
				if (!s.empty()) { //스택에 괄호가 남아 있다면 걔한테 값을 더해
					s.top().second += 2;
				}
				else { //스택에 괄호가 없다면 결과에 값을 더해
					sum += 2;
				}

			}
			else {
				//값이 있다면 괄호를 품은 친구기 때문에 곱 연산을 바로 함
				num = 2 * s.top().second;
				s.pop();
				if (!s.empty()) {
					s.top().second += num;
				}
				else {
					sum += num;
				}

			}
		}


		else if (str[i] == ']') {
			//닫는 괄호 시 스택 비어있는지 확인
			if (s.empty() || s.top().first != '[') {
				isbreak = true;
				break;
			}

			if (s.top().second == 0) {

				s.pop();
				if (!s.empty()) {
					s.top().second += 3;
				}
				else {
					sum += 3;
				}

			}
			else {
				num = 3 * s.top().second;  //값이 있다는 건 괄호쌍을 품은 괄호쌍임
				s.pop();
				if (!s.empty()) {
					s.top().second += num;
				}
				else {
					sum += num;
				}

			}
		}

	}
		////비었다면 괄호쌍이 다 나온것임.
		//if (s.empty()) {
		//	sum += num; //num을 최종 sum에 더함
		//	num = 0; //0으로 초기화
		//}
	

	if (!isbreak && s.empty()) cout << sum;
	else cout << 0;

	
}