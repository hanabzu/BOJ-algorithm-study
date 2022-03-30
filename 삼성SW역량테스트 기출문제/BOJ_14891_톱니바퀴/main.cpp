/* BOJ_14891 톱니바퀴 */
/* hanabzu */

#include <iostream>

using namespace std;

string s[4];
int p[4][2] = { {6,2},{6,2},{6,2},{6,2} };
int K, N, D, ans = 0;

void rotate(int n, int d, int flag);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
	}
	cin >> K;
	while (K--) {
		cin >> N >> D;
		rotate(N - 1, D, 0);
	}

	for (int i = 0; i < 4; i++) {
		ans += ((s[i][(p[i][1] + 6) % 8] - '0') << i);
	}
	cout << ans;
	return 0;
}

void rotate(int n, int d, int flag) {
	if (flag != 2 && n > 0 && s[n][p[n][0]] != s[n - 1][p[n - 1][1]]) {
		rotate(n - 1, -d, 1);
	}
	if (flag != 1 && n < 3 && s[n][p[n][1]] != s[n + 1][p[n + 1][0]]) {
		rotate(n + 1, -d, 2);
	}


	p[n][0] = (p[n][0] - d + 8) % 8;
	p[n][1] = (p[n][1] - d + 8) % 8;
}