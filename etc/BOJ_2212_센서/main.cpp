/* BOJ_2212 센서 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10000;
int N, K, A[MAXN], dis[MAXN], ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);
	for (int i = 0; i < N - 1; i++) {
		dis[i] = A[i + 1] - A[i];
	}

	for (int i = 0; i < K - 1; i++) {
		*max_element(dis, dis + N - 1) = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		ans += dis[i];
	}

	cout << ans;
	return 0;
}