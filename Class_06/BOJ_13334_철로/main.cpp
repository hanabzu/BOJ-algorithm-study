/* BOJ_13334 철로 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 100000;

struct Line {
	int start = 0, end = 0;
	Line(int h, int o) :start(h), end(o) {}
	Line() {}

	bool operator<(const Line& rhs) const {
		if (this->end == rhs.end) {
			return this->start < rhs.start;
		}
		else {
			return this->end < rhs.end;
		}
	}
};

int N, lhs, rhs, h, o, D, ans = 0;
Line line[MAXN];
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h >> o;
		if (h > o) swap(h, o);
		line[i] = Line(h, o);
	}
	cin >> D;
	
	sort(line, line + N);
	
	for (int i = 0; i < N; i++) {
		rhs = line[i].end;
		lhs = rhs - D;

		if (lhs <= line[i].start) {
			q.push(line[i].start);
		}

		while (!q.empty() && q.top() < lhs) {
			q.pop();
		}

		ans = max(ans, (int)q.size());
	}

	cout << ans;
	return 0;
}