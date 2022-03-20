/* BOJ_6588 골드바흐의 추측 */
/* hanabzu */

#include <iostream>
#define MAXN 1000000

using namespace std;

int t, a;
bool visit[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int s = 2; s < MAXN; s++) {
		if (!visit[s]) {
			int i = s<<1;
			while (i <= MAXN) {
				if (!visit[i]) {
					visit[i] = true;
				}
				i += s;
			}
		}
	}

	cin >> t;
	while (t--) {
		cin >> a;
		if (!a) break;
		int cnt = 0;
		for (int i = 2; i <= a>>1; i++) {
			if ((!visit[i]) && (!visit[a - i])) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}