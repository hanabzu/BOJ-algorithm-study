/* BOJ_10942 팰린드롬? */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2000;

int N, M, S, E;
int n[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

bool isPalindrome(int s, int e);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> n[i];
	}
	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << isPalindrome(S, E) << '\n';
	}

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

	dp[s][e] = (n[s] == n[e]) ? true : false;

	if (e - s > 1) {
		dp[s][e] = dp[s][e] & isPalindrome(s + 1, e - 1);
	}
	
	return dp[s][e];
}