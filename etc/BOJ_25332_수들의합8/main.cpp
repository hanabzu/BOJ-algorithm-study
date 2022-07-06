/* BOJ_25332 수들의 합 8 */
/* hanabzu */

#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
const int MAXN = 200000;

int N;
ll A[MAXN + 1], B[MAXN + 1], AB[MAXN + 1], ans = 0;
map<ll, ll> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
	}
	m[0]++;
	for (int i = 1; i <= N; i++) {
		AB[i] =  A[i] - B[i];
		auto it = m.find(AB[i]);
		if (it != m.end()) {
			ans += (*it).second;
		}
		m[AB[i]]++;
	}

	cout << ans;
	return 0;
}
