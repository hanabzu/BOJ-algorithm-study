/* hanabzu */
/* BOJ_9095 1,2,3 더하기 */

#include <iostream>
using namespace std;

int memo[11] = { 0, };

int count(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;

	memo[0] = 1;
	memo[1] = 2;
	memo[2] = 4;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << count(n - 1) << '\n';
	}

	return 0;
}

int count(int n) {
	if (memo[n] != 0) {
		return memo[n];
	}

	memo[n] = count(n - 1) + count(n - 2) + count(n - 3);
	return memo[n];
}