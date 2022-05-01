/* BOJ_21611 마법사 상어와 블리자드 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAXN = 49;
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int N, M, d, s, R, C, page = 0, ans = 0;
int A[MAXN][MAXN];
vector<int> v[2];

void blizzard();
void explode();
void relocate();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	R = C = (N >> 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	while (M--) {
		blizzard();
		explode();
		relocate();
	}

	cout << ans;

	return 0;
}

void blizzard() {
	cin >> d >> s;
	if (d == 1) d = 3;
	else if (d == 2) d = 1;
	else if (d == 3) d = 0;
	else d = 2;

	for (int i = 1; i <= s; i++) {
		A[R + i * dx[d]][C + i * dy[d]] = 0;
	}

	int r = R, c = C, turn = 0, cnt = 1;
	d = 0;
	// read marbles
	while (!(r == 0 && c == 0)) {
		if (A[r][c] != 0) {
			v[page].push_back(A[r][c]);
		}

		r += dx[d];
		c += dy[d];

		if (++turn == cnt) {
			turn = 0;
			d = (d + 1) % 4;
			if ((d & 1) == 0) cnt++;
		}
	}

}

void explode() {
	bool flag = true;

	int n, cnt;

	while (flag) {
		n = 0, cnt = 0;
		flag = false;
		for (int i = 0; i < v[page].size(); i++) {
			if (v[page][i] == n) { // same num
				cnt++;
			}
			else {
				if (cnt < 4) { // less than 4
					for (int k = 0; k < cnt; k++) {
						v[page ^ 1].push_back(n);
					}
				}
				else { // explode
					flag = true;
					ans += n * cnt;
				}
				n = v[page][i];
				cnt = 1;
			}
		}
		if (cnt < 4) {
			for (int k = 0; k < cnt; k++) {
				v[page ^ 1].push_back(n);
			}
		}
		else {
			ans += n * cnt;
		}
		
		v[page].clear();
		page ^= 1;
	}
}

void relocate() {
	int n = 0, cnt = 0;

	v[page ^ 1].push_back(0);
	for (int i = 0; i < v[page].size(); i++) {
		if (v[page][i] == n) { // same num
			cnt++;
		}
		else {
			if (n != 0) {
				v[page ^ 1].push_back(cnt);
				v[page ^ 1].push_back(n);
			}
			n = v[page][i];
			cnt = 1;
		}
	}
	v[page ^ 1].push_back(cnt);
	v[page ^ 1].push_back(n);

	v[page].clear();
	page ^= 1;

	memset(A, 0, sizeof A);
	int r = R, c = C, turn = 0, i = 0;
	cnt = 1;
	d = 0;

	//write marbles
	while (i < v[page].size() && !(r == 0 && c == 0)) {
		A[r][c] = v[page][i++];

		r += dx[d];
		c += dy[d];

		if (++turn == cnt) {
			turn = 0;
			d = (d + 1) % 4;
			if ((d & 1) == 0) cnt++;
		}
	}
	v[page].clear();
}