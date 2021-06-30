/* hanabzu */
/* BOJ_6064 카잉 달력 */

#include <iostream>

using namespace std;

int T, M, N, x, y;

void cain();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;
		cain();
	}
	return 0;
}

void cain() {
	for (int i = 0; i <= N; i++) {
		if ((x - y) % N == 0) {
			cout << x << '\n';
			return;
		}
		x += M;
	}
	cout << -1 << '\n';
}