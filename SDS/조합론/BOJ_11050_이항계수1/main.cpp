/* BOJ_11050 이항계수 1 */
/* hanabzu */

#include <iostream>

using namespace std;

int N, K, ans;

int main() {
	cin >> N >> K;

	ans = 1;
	for (int i = N; i > N - K; i--) {
		ans *= i;
	}
	for (int i = 2; i <= K; i++) {
		ans /= i;
	}

	cout << ans;
	return 0;
}

