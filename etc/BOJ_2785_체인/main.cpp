/* BOJ_2785 체인 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500000;
int N, cnt, ans, p;
long long L[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cnt = N - 1;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}

	sort(L, L + N);
	while (cnt > 0) {
		if (L[p] < cnt) {
			cnt -= (L[p] + 1);
			ans += L[p];
			p += 1;
		}
		else {
			ans += cnt;
			cnt = 0;
		}

	}
	cout << ans;
	return 0;
}