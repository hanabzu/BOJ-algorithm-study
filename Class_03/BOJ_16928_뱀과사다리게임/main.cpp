/* hanabzu */
/* BOJ_16928 뱀과 사다리 게임 */

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int N, M, x, y, turn = 1;
bool found[100] = { 0, };
map<int, int> ladnake;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> x >> y;
		ladnake[--x] = --y;
	}

	q.push(0);
	found[0] = 1;
	int q_count = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int dice = 1; dice < 7; dice++) {
			int next = u + dice;
			if (ladnake.count(next)) {
				found[next] = 1;
				next = ladnake[next];
			}
			if (next == 99) {
				cout << turn;
				return 0;
			}
			if (next < 100) {
				if (found[next] == 0) {
					q.push(next);
					found[next] = 1;
				}
			}
		}
		if (--q_count == 0) {
			q_count = q.size();
			turn++;
		}
	}
}