/* BOJ_1019 책 페이지 */
/* hanabzu */

#include <iostream>

using namespace std;

int N, ans[10], p = 1;

void cal(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (1) {
		while (N % 10 != 9 && N > 0) {
			cal(N);
			N--;
		}
		if (N == 0) break;

		N /= 10;
		ans[0] += N * p;
		for (int i = 1; i < 10; i++) {
			ans[i] += (N + 1) * p;
		}
		p *= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}

void cal(int n) {
	while (n > 0) {
		ans[n % 10] += p;
		n /= 10;
	}
}