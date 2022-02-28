/* BOJ_3015 오아시스 재결합 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 500000;

int N, n, top = -1, flag = 0;
pair<long long, int> s[MAXN];
long long ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {
		cin >> n;

		if (top < 0) { // stack is empty
			s[++top] = make_pair(n, 1);
		}
		else {
			while (top >= 0 && s[top].first <= n) {
				if (s[top].first == n) {
					flag = s[top].second;
				}
				ans += s[top].second;
				top--;
			}

			if (top >= 0) ans++;

			s[++top] = make_pair(n, 1 + flag);
			flag = 0;
		}
	}

	cout << ans;

	return 0;
}
