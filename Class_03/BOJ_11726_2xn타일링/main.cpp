/* hanabzu */
/* BOJ_11726 2×n 타일링 */

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
	memo[1] = 2;

	cout << tiling(n - 1);

	return 0;
}

int tiling(int n) {
	if (memo[n] != 0) {
		return memo[n];
	}

	memo[n] = (tiling(n - 2) + tiling(n - 1)) % 10007;
	return memo[n];
}