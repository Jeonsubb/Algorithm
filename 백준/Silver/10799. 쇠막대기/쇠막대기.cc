#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;



//1차 시도 -> 시간제한 1초일 때 시간 복잡도가 O(N^2)이 되므로 좋지 않은 코드
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	string str;
//	cin >> str;
//
//	vector<pair<int,int>>result; //얘는 시작과 끝 지점을 포함해야 됨
//	stack<int>s; //인덱스를 포함해서 괄호쌍을 스택에 저장 -> 인덱스를 저장
//	int cnt = 0; //조각 개수 = 막대에 포함되는 레이저 개수 +1
//	//예시
//	//(())
//	//0 1 2 3 그럼 레이저의 위치는 2로 막대기의 위치는 0,3으로 저장
//	
//	//레이저랑 막대기랑 구분을 해야 됨
//	//pop이 일어날때의 인덱스와 push된 (랑 인덱스 차이가 1일 때 레이저
//	//레이저는 레이저따로 인덱스 저장하는 배열 필요
//	vector<int>rasor;
//
//	for (int i = 0; i < str.length(); i++) {
//		if (str[i] == '(') s.push(i);
//		else if (str[i] == ')') {
//			if(i-s.top()>1) result.push_back({ s.top(),i }); //top의 인덱스와 ')'의 인덱스를 저장
//			
//			//얘는 레이저 위치 저장
//			else {
//				rasor.push_back(i);
//			}
//			s.pop();
//		}
//	}
//
//	
//	//이중 반복문인데 괜찮은가..?
//	for (auto X : result) {
//		for (int r : rasor) {
//			if (X.second > r&& X.first<r) cnt++; //막대기의 끝 지점과 레이저의 끝 지점 비교해서 
//			//해당 인덱스보다 작으며 포함
//		}
//		cnt++; //레이저 개수 +1이 잘린 개수니깐..
//	}
//	cout << cnt;
//
//
//
//}



int main() {

	string str;
	cin >> str;

	stack<int>s;

	int cnt = 0;
	for (int i = 0;i<str.length();i++) {
		if (str[i] == '(') s.push(i);
		
		// )일때 상황
		else {
			//레이저: () 바로 들어왔을 때
			if (s.top() == i - 1) {
				s.pop(); //레이저는 날리고
				cnt += s.size(); //스택에 포함되어 있는 막대기 수를 더함
			}
			//막대기를 닫을 때: 막대기 개수 하나 더해줘야 됨
			else {
				s.pop();
				cnt += 1;
			}
		}
	}

	cout << cnt;



}