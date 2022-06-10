/* BOJ_1459 걷기 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

long long X, Y, W, S, ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> Y >> W >> S;

	if ((W << 1) < S) {
		ans = (X + Y) * W;
	}
	else {
		int short_dis = min(X, Y);
		int left_dis = max(X, Y) - short_dis;

		ans += short_dis * S;

		if (S < W) {
			ans += (left_dis >> 1) * (S << 1);
		}
		else {
			ans += (left_dis >> 1) * (W << 1);
		}

		if ((left_dis & 1) == 1) { // odd
			ans += W;
		}
	}

	cout << ans;

	return 0;
}