/* BOJ_3109 빵집 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXR = 10000;
const int dr[3] = { -1,0,1 };

int R, C, ans = 0;
string s[MAXR];

bool dfs(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < R; i++) {
		dfs(i, 0);
	}

	cout << ans;

	return 0;
}


bool dfs(int r, int c) {
	if (c == C - 1) {
		ans++;
		return true;
	}

	for (int d = 0; d < 3; d++) {
		int nr = r + dr[d];

		if (nr < 0 || nr >= R || s[nr][c + 1] == 'x') continue;

		s[nr][c + 1] = 'x';
		if (dfs(nr, c + 1)) return true;
	}
	return false;
}