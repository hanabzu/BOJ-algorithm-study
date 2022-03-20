/* BOJ_11653 소인수분해 */
/* hanabzu */

#include <iostream>
#include <vector>
#define MAXN 10000000

using namespace std;

int N;
bool visit[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int s = 2; s <= N; s++) {
		if (!visit[s]) {
			int i = s << 1;
			while (i <= N) {
				if (!visit[i]) {
					visit[i] = true;
				}
				i += s;
			}
		}
	}
	int n = N;
	for (int i = 2; i <= N; i++) {
		if (visit[i]) continue;

		while (!(n % i)) {
			cout << i << '\n';
			n /= i;
		}
		if (n == 1) break;
	}

	return 0;
}