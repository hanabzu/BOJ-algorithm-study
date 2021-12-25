/* BOJ_13549 숨바꼭질3 */
/* hanabzu */

#include <iostream>
#include <queue>

using namespace std;

queue<int> q, tq;
bool visit[100001];
int N, K, u, tu, t = 0;
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	q.push(N);

	bfs();

	return 0;
}

void bfs() {
	while (1) {
		while (!q.empty()) {
			u = q.front();
			q.pop();
			while (1) {
				if (u == K) { // can move
					cout << t;
					return;
				}
				if (!visit[u]) {
					visit[u] = true;
					tq.push(u);
				}
				u = u << 1;
				if (u==0 || u > 100000) {
					break;
				}
			}

		}

		t++;

		while (!tq.empty()) {
			u = tq.front();
			tq.pop();
			int fu = u - 1, bu = u + 1;
			if (fu >=0 && !visit[fu]) {
				q.push(fu);
			}
			if (bu <=100000 && !visit[bu]) {
				q.push(bu);
			}
		}
	}
}