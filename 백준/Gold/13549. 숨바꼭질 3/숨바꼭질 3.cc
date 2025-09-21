#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int chk[100001];
int brd[100001];
int r[3] = { -1,2,1 };

int main() {
	fill(chk, chk + 100001, -1);
	int ne, m;
	cin >> ne >> m;
	queue<int> q;
	q.push(ne);
	chk[ne] = 0; //해당 숫자를 넣었음을 체크

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
				
		for (int i = 0; i < 3; i++) {
			int n;
			int s = chk[cur]; //시간 기록
			if (i != 1) {//한칸 이전, 한칸 이후
				n = cur + r[i];
				s++;
				if (n < 100001) {
					if (chk[n] == -1) {

						q.push(n);
						chk[n] = s;


					}
					else {
						if (chk[n] > s) {
							q.push(n);
							chk[n] = s;
						}
					}
				}
				else continue;
				
				
			}
			else {//곱하기 2 처리
				n = cur * r[i];
				if (n < 100001) {
					if (chk[n] == -1) {

						q.push(n);
						chk[n] = s;


					}
				
					else {
						if (chk[n] > s) {
							q.push(n);
							chk[n] = s;
						}
					}
				}
				else continue;
			
			}
			

		}
	}

	std::cout << chk[m];


	}