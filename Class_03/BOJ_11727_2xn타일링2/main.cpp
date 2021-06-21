/* hanabzu */
/* BOJ_11727 2×n 타일링 2 */

#include <iostream>

using namespace std;

int memo[1000]{ 0, };

int tiling(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	memo[0] = 1;
	memo[1] = 3;

	cout << tiling(n-1);

	return 0;
}

int tiling(int n) {
	if (memo[n] != 0) {
		return memo[n];
	}

	memo[n] = ((tiling(n - 2) << 1) + tiling(n - 1)) % 10007;
	return memo[n];
}
