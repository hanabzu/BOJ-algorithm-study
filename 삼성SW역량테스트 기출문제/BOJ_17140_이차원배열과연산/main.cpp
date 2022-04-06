/* BOJ_17140 이차원 배열과 연산 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

const int MAXN = 100;
struct Num {
	int num, cnt;
	Num() {}
	Num(int n, int c) : num(n), cnt(c) {}
	bool operator<(const Num& rhs) const {
		if (cnt == rhs.cnt) {
			return num > rhs.num;
		}
		return cnt > rhs.cnt;
	}
};

int r, c, k, t = 0, row = 3, col = 3;
int A[MAXN<<1][MAXN<<1], cnt[MAXN + 1];
priority_queue<Num> q;
void R();
void C();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	r--; c--;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> A[i][j];
		}
	}

	while (A[r][c] != k) {
		if (row >= col) {
			R();
		}
		else {
			C();
		}
		t++;
		if (t > 100) {
			t = -1; break;
		}
	}

	cout << t;
	return 0;
}

void R() {
	int nc = 0;
	for (int i = 0; i < row; i++) {
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < col; j++) {
			cnt[A[i][j]]++;
		}
		for (int j = 1; j <= MAXN; j++) {
			if (cnt[j] != 0) {
				q.push(Num(j, cnt[j]));
			}
		}
		int p = 0;
		memset(A[i], 0, sizeof A[i]);
		while (!q.empty()) {
			A[i][p++] = q.top().num;
			A[i][p++] = q.top().cnt;
			q.pop();
		}
		nc = max(nc, min(p, MAXN));
	}
	col = nc;
}

void C() {
	int nr = 0;
	for (int i = 0; i < col; i++) {
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < row; j++) {
			cnt[A[j][i]]++;
		}
		for (int j = 1; j <= MAXN; j++) {
			if (cnt[j] != 0) {
				q.push(Num(j, cnt[j]));
			}
		}
		int p = 0;
		for (int j = 0; j < MAXN; j++) {
			A[j][i] = 0;
		}
		while (!q.empty()) {
			A[p++][i] = q.top().num;
			A[p++][i] = q.top().cnt;
			q.pop();
		}
		nr = max(nr, min(p, MAXN));
	}
	row = nr;
}