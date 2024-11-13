#include <queue>
#include <iostream>
using namespace std;

int bored[1000002] = { 0 };
bool vis[1000002];
int m[1000002];

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	//f는 건물 전체 층수
	//g는 갈려고 하는 층수
	//s는 강호가 있는 층
	//u는 u층만큼 올라감
	//d는 d층만큼 내려감

	
	
	queue<int>Q;

	bored[g] = 2; //g층
	Q.push(s); //s층을 큐에 삽입
	m[s] = 0;
	vis[s] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur==g) {
			cout << m[cur];
			return 0;
		}

		
		int nu = cur + u;
		int nd = cur - d;
		if (nu<=f&&!vis[nu]) {
			Q.push(nu);
			vis[nu] = 1;
			m[nu] = m[cur] + 1;
		}
		
		if (nd>=1&&!vis[nd]) {
			Q.push(nd);

			vis[nd] = 1;

			m[nd] = m[cur] + 1;
		}

		
		//if(vis[nd]||vis[nu]) continue; 처음에는 이렇게 코드를 짰는데 이래하면
		//  둘 중 하나만 방문 했어도 넘어가게 되어서 문제임
	}

	//while을 그냥 나온거라면 엘리베이터로 이동 못한다는 것
	cout << "use the stairs";









}