#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
//tuple 함수
//get<index>(tuple이름) -> 해당 인덱스에 해당하는 튜플 값 불러옴
//람다함수 -> [capture](인자) -> 반환형 {} ... 반환 타입은 cppp 14부터 생략 가능
//람다함수는 기본적으로 함수 내부에 선언된 변수만 사용 가능하지만, 캡처를 통해 외부 변수를 가져와서 사용 가능

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<tuple<int, string,int>>v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int n;
		string s;
		cin >> n >> s;
		tuple<int, string, int>t;
		t = make_tuple(n, s, i);
		v.push_back(t);
	}

	//첫번째 인자가 나이이므로 정렬 가능 , 순서..  
	//외부 함수로 정의한다면 튜플이나 pair를 인자로 받게 하면 되겠다.
	sort(v.begin(), v.end(), [](tuple<int, string, int>a, tuple<int, string, int>b) {

		if (get<0>(a) == get<0>(b)) {
			return get<2>(a) < get<2>(b);
		}
		return get<0>(a) < get<0>(b);

		});

	for (int i = 0; i < n; i++) {
		cout << get<0>(v[i]) << " " << get<1>(v[i]) << "\n";
	}
	



}