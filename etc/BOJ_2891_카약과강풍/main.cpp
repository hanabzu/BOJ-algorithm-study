/* BOJ_2891 카약과 강풍 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10;
int N, S, R, a, ans = 0;
bool s[MAXN + 1], r[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S >> R;

	for (int i = 0; i < S; i++) {
		cin >> a;
		s[a] = true;
	}
	for (int i = 0; i < R; i++) {
		cin >> a;

		if (s[a] == true) {
			s[a] = false;
		}
		else {
			r[a] = true;
		}

	}

	for (int i = 1; i <= N; i++) {
		if (s[i] == true) {
			if (i - 1 > 0 && r[i - 1] == true) {
				r[i - 1] = false;
			}
			else if (i + 1 <= N && r[i + 1] == true) {
				r[i + 1] = false;
			}
			else {
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}