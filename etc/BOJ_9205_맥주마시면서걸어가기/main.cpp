/* BOJ_9205 맥주 마시면서 걸어가기 */
/* hanabzu */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 100;

int T, N, hX, hY, cX[MAXN], cY[MAXN], pX, pY;
bool visit[MAXN];

void testcase();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--) {
		testcase();
	}

	return 0;
}

void testcase() {
	
	cin >> N >> hX >> hY;
	for (int i = 0; i < N; i++) {
		cin >> cX[i] >> cY[i];
	}
	cin >> pX >> pY;

	fill(visit, visit + N, false);
	queue<pii> q;
	q.push(make_pair(hX, hY));

	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		if ((abs(X - pX) + abs(Y - pY)) <= 1000) {
			cout << "happy\n";
			return;
		}

		for (int i = 0; i < N; i++) {
			if (visit[i] || (abs(X - cX[i]) + abs(Y - cY[i])) > 1000) continue;

			visit[i] = true;
			q.push(make_pair(cX[i], cY[i]));
		}
	}

	cout << "sad\n";
}