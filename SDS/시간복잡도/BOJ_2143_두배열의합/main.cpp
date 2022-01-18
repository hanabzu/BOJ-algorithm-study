/* BOJ_2143 두 배열의 합 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 1000
using namespace std;
int T, N, M;
int n[MAXN+1], m[MAXN+1];
vector<long long> vn, vm;
long long cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
		n[i] += n[i - 1];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> m[i];
		m[i] += m[i - 1];
	}

	for (int nl = 0; nl < N; nl++) {
		for (int nr = nl + 1; nr <= N; nr++) {
			vn.push_back(n[nr] - n[nl]);
		}
	}

	for (int ml = 0; ml < M; ml++) {
		for (int mr = ml + 1; mr <= M; mr++) {
			vm.push_back(m[mr] - m[ml]);
		}
	}

	sort(vm.begin(), vm.end());

	for (vector<long long>::iterator it = vn.begin(); it != vn.end(); it++) {
		cnt += upper_bound(vm.begin(), vm.end(), T - (*it)) - lower_bound(vm.begin(), vm.end(), T - (*it));
	}

	cout << cnt;

	return 0;
}
