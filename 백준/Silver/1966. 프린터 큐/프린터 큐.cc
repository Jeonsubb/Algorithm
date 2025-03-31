#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//큐에 있는 문서의 중요도 확인, 
	// 큐 안에 현재 문서보다 중요도 높은 문서가 존재한다면 가장 뒤로
	//벡터 안에 넣고 sort 돌리고, 위치 찾기 ... 굳이 큐로 하는가 
	//-> 11911 중요도에 0번째 인덱스 출력 순서 찾을려면 큐 해야 되네,,,,
	//하나하나 꺼내서 확인하고 뒤로 보내는게 말이 안됨
	// 등수랑 pop의 횟수를 비교? , 인덱스도 넣는다?
	//숫자간 등수가 출력순서임 사실, 같은 숫자가 존재한다면?
	
	//내가 원하는 인덱스가 pop이 될때까지 반복..
	
	//테스트케이스 수
	int t;
	cin >> t;

	while (t--) {
		//문서 개수
		int n, m;
		cin >> n >> m;

		queue<pair<int,int>>Q;
		vector<int>v(n);

		//Q에 인덱스와 중요도 넣기, 벡터에 sort 시키고, 큰 값이 있는지 찾기
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v[i] = num;
			pair<int, int>p = { i, num };
			Q.push(p);
		}

		//벡터 오름차순 정렬.... greater<int> 넣기!
		sort(v.begin(), v.end(),greater<int>());

		//출력순서
		int cnt = 0; 
		int idx = 0;
		//문서가 1개일 때
		if (Q.size() == 1) {
			//cout << "1번째 출력" << "\n";
			cout << cnt+1 << "\n";
			continue;
		}
		



		else {
			while (1) {
				pair<int, int>cur = Q.front();
				//최대랑 크기가 같을 때
				if (cur.second==v[idx]) {
					//m에 도달
					if (cur.first == m) {

						//cout << "2번째 출력" << "\n";
						cout << cnt+1 << "\n";
						break;
					}
					else {
						idx++;
						cnt++;
						Q.pop();
					}
				}
				//최대랑 크기가 다를 때
				else {
					//뒤에 넣기
					Q.push(cur);

					Q.pop();
				}



			}
		}



	}


}