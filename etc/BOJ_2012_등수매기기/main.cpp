/* BOJ_2012 등수 매기기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500000;

int N, A[MAXN + 1];
long long ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	sort(A + 1, A + N + 1);

	for (int i = 1; i <= N; i++) {
		ans += abs(i - A[i]);
	}

	cout << ans;

	return 0;
}