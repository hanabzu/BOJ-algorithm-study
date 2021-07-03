/* hanabzu */
/* BOJ_9465 스티커 */

#include <iostream>
#include <algorithm>

using namespace std;

int T, n;
bool check[2][100000] = { 0, };
int memo[2][100000] = { 0, };
int value[2][100000] = { 0, };

void sticker();
int max_value(int line, int n);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		sticker();
	}

	return 0;
}

void sticker() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> value[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> value[1][i];
	}
	memo[0][0] = value[0][0];
	memo[1][0] = value[1][0];
	check[0][0] = check[1][0] = 1;
	if (n == 1) {
		cout << max(memo[0][0], memo[1][0])  << '\n';
	}
	else {
		memo[0][1] = value[1][0] + value[0][1];
		memo[1][1] = value[0][0] + value[1][1];
		check[0][1] = check[1][1] = 1;
		cout << max(max_value(0, n - 1), max_value(1, n - 1)) << '\n';
	}

	fill(check[0], check[0] + n, 0);
	fill(check[1], check[1] + n, 0);
}

int max_value(int line, int n) {
	if (check[line][n]) {
		return memo[line][n];
	}
	
	memo[line][n] = max(max_value((line + 1) % 2, n - 1), max_value((line + 1) % 2, n - 2)) + value[line][n];
	check[line][n] = 1;
	return memo[line][n];
}