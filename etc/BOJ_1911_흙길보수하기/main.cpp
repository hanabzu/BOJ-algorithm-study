/* BOJ_1911 흙길 보수하기 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 10000;

int N, L, a, b;
vector<pii> hole;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		hole.push_back(make_pair(a, b));
	}

	sort(hole.begin(), hole.end());

	int ans = 1;
	int p = 1;
	int s = hole[0].first, e = hole[0].second;
	int cover = s + L;

	while (true) {
		if (cover < e) {
			cover += L;
			ans++;
		}
		else {
			if (p >= N) break;
			s = hole[p].first;
			e = hole[p++].second;

			if (cover < s) {
				cover = s + L;
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}