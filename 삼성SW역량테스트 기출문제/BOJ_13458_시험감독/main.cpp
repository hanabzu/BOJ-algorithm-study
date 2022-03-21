/* BOJ_13458 시험 감독 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
int N, A[MAXN], B, C;
long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	ans = N;
	for (int i = 0; i < N; i++) {
		A[i] = max(0, A[i] - B);
		ans += A[i] / C;
		if (A[i] % C != 0) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}