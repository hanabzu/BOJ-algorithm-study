/* BOJ_14939 불 끄기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_ANS = 1000;
const int N = 10;
const int T1 = (1 << 9);
const int T3 = (7 << 8);
string s;
int lights[N], ans = MAX_ANS;

void dfs(int cnt, int p);
int cal(int (&tmp)[N]);
void flip(int r, int c, int(&bulb)[N]);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'O') {
				lights[i] |= (1 << (N - j - 1));
			}
		}
	}
	dfs(0, 0);

	if (ans == MAX_ANS) {
		cout << -1;
	}
	else {
		cout << ans;
	}


	return 0;
}

void dfs(int cnt, int r) {
	if (r == N) {
		int tmp[N];
		memcpy(tmp, lights, sizeof(lights));
		ans = min(ans, cnt + cal(tmp));
		return;
	}

	dfs(cnt, r + 1);

	flip(r, 0, lights);

	dfs(cnt + 1, r + 1);

	flip(r, 0, lights);
}

int cal(int (&bulb)[N]) {
	int cnt = 0;
	for (int c = 1; c < N; c++){
		for (int r = 0; r < N; r++) {
			if (bulb[r] & (T1 >> (c - 1))) {
				flip(r, c, bulb);
				cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (bulb[i] != 0) {
			return MAX_ANS;
		}
	}
	return cnt;
}

void flip(int r, int c, int(&bulb)[N]) {
	if (r - 1 >= 0) {
		bulb[r - 1] ^= (T1 >> c);
	}
	if (r + 1 < N) {
		bulb[r + 1] ^= (T1 >> c);
	}

	bulb[r] ^= ((T3 >> c) & ((1 << N) - 1));
}