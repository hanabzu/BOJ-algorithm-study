/* BOJ_2306 유전자 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500;
string s;
int dp[MAXN][MAXN], ans = 0;

int get_max(int lhs, int rhs);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dp[0][0], &dp[MAXN - 1][MAXN], -1);

	cin >> s;
	
	cout << get_max(0, s.size() - 1);
	return 0;
}

int get_max(int lhs, int rhs) {
	int& res = dp[lhs][rhs];

	if (res >= 0) return res;
	if (lhs >= rhs) return res = 0;

	res = 0;
	for (int i = lhs; i < rhs; i++) {
		if (s[i] == 'a' || s[i] == 'g') {
			for (int j = rhs; j > i; j--) {
				if ((s[i] == 'a' && s[j] == 't') || (s[i] == 'g' && s[j] == 'c')) {
					res = max(res, 2 + get_max(lhs, i - 1) + get_max(i + 1, j - 1) + get_max(j + 1, rhs));
					break;
				}
			}
		}
	}

	return res;
}
