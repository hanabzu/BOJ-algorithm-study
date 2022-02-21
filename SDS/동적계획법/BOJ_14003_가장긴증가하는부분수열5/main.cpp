/* BOJ_14003 가장 긴 증가하는 부분 수열 5 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000000;
const int INF = 1987654321;
int N;
int n[MAXN + 1];
int d[MAXN + 1];
int p[MAXN + 1];
vector<int> x, v;
int ans[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
	}

	x.push_back(-INF);

	for (int i = 1; i <= N; i++) {
		int idx = lower_bound(x.begin(), x.end(), n[i]) - x.begin();
		p[i] = idx;
		if (idx == x.size()) {
			x.push_back(n[i]);
		}
		else {
			x[idx] = n[i];
		}
		ans[i] = x.size() - 1;
	}

	int m = ans[N];
	for (int pos = N; pos > 0; pos--) {
		if (p[pos] == m) {
			v.push_back(n[pos]);
			m--;
		}
	}

	cout << ans[N] << '\n';

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		cout << *it << ' ';
	}

	return 0;
}