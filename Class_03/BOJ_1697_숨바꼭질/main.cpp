/* hanabzu */
/* BOJ_1697 숨바꼭질 */

#include <iostream>
#include <queue>
using namespace std;

int N, K, t = 1;

bool found[100001] = { 0, }; // 0 ~ 100000
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	if (N >= K) {
		cout << N - K;
	}
	else { // bfs
		q.push(N);
		found[N] = 1;
		int q_count = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			int next[3] = { u - 1, u + 1, u << 1 };
			for (int i = 0; i < 3; i++) {
				if (next[i] == K) {
					cout << t;
					return 0;
				}
				if (next[i] >= 0 && next[i] <= 100000) { // boundary check
					if (found[next[i]] == 0) {
						q.push(next[i]);
						found[next[i]] = 1;
					}
				}
			}
			
			if (--q_count == 0) {
				q_count = q.size();
				t++;
			}
		}
	}
}