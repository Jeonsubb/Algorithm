#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length(); //< 오름차순 -----  > 내림차순
	else return s1 < s2; //사전순 뒤에가 큰거네
}


int main() {
	int n;
	cin >> n;
	vector<string>v;
	
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	//이 상황에서 sort를 쓸려면 templete으로 가는거 같은데.. ---> 비교 함수 정의해서 sort의 인수로 추가!


	sort(v.begin(), v.end(), comp);
	

	//unique 함수는 중복 원소를 벡터의 제일 뒤로 보낸다! 그러고 중복 값 시작점을 반환
	//erase 함수는 해당 구간을 지운다.
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto a : v) cout << a << endl;




}