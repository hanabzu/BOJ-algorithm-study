/* BOJ_1208 부분수열의 합 2 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

const int MAXN = 40;
int N, S;
long long n, m, ans = 0;
vector<long long> a, b, A, B;

void dfs(vector<long long>& a, vector<long long>& A, int depth, long long s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < (N >> 1); i++) {
		cin >> n >> m;
		a.push_back(n);
		b.push_back(m);
	}
	if ((N & 1) == 1) {
		cin >> n;
		b.push_back(n);
	}

	dfs(a, A, 0, 0);
	dfs(b, B, 0, 0);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < A.size(); i++) {
		ans += upper_bound(B.begin(), B.end(), S - A[i]) - lower_bound(B.begin(), B.end(), S - A[i]);
	}
	if (S == 0) ans--;
	cout << ans;
	return 0;
}

void dfs(vector<long long>& a, vector<long long>& A, int depth, long long s) {
	if (depth == a.size()) {
		A.push_back(s);
		return;
	}

	dfs(a, A, depth + 1, s);
	dfs(a, A, depth + 1, s + a[depth]);
}
