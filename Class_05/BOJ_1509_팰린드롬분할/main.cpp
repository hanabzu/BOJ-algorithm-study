/* BOJ_1509 팰린드롬 분할 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2500;

string str;
int dp[MAXN][MAXN];
int minlen[MAXN + 1];

bool isPalindrome(int s, int e);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	for (int j = 1; j <= str.size(); j++) {
		minlen[j] = MAXN;
		for (int i = 1; i <= j; i++) {
			if (isPalindrome(i - 1, j - 1)) {
				minlen[j] = min(minlen[j], minlen[i - 1] + 1);
			}
		}

	}
	cout << minlen[str.size()];

	return 0;
}


bool isPalindrome(int s, int e) {
	if (s == e) {
		return true;
	}
	else if (dp[s][e] == 1) {
		return true;
	}
	else if (dp[s][e] == -1) {
		return false;
	}

	dp[s][e] = (str[s] == str[e]) ? 1 : 0;

	if (e - s > 1) {
		dp[s][e] = dp[s][e] & isPalindrome(s + 1, e - 1);
	}

	if (dp[s][e] == 0) dp[s][e] = -1;
	return (dp[s][e] == 1) ? true : false;
}