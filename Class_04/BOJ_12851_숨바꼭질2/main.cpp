/* hanabzu */
/* BOJ_12851 숨바꼭질 2 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K, t = 1, r = 0;

bool found[100001] = { 0, }; // 0 ~ 100000
queue<int> q;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	if (N >= K) {
		cout << N - K << '\n' << 1;
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
					r++;
				}
				if (next[i] >= 0 && next[i] <= 100000) { // boundary check
					if (found[next[i]] == 0) {
						q.push(next[i]);
						v.push_back(next[i]);
					}
				}
			}

			if (--q_count == 0) {
				if (r > 0) {
					cout << t << '\n' << r;
					return 0;
				}
				for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
					found[*it] = 1;
				}
				v.clear();
				q_count = q.size();
				t++;
			}
		}
	}

}