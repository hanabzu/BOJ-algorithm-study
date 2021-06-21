/* hanabzu */
/* BOJ_9461 파도반 수열*/

#include <iostream>

using namespace std;

unsigned long long triangle(unsigned long long);
unsigned long long memo[100] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;
	
	memo[0] = memo[1] = memo[2] = 1;
	memo[3] = memo[4] = 2;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << triangle(N - 1) << '\n';
	}
}

unsigned long long triangle(unsigned long long n) {
	if (memo[n] != 0) {
		return memo[n];
	}

	memo[n] = triangle(n - 1) + triangle(n - 5);
	return memo[n];
}