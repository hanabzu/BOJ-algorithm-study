/* BOJ_1806 부분합 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

int num[100001];
int N, S ;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int left = 0, right = 0, sum = 0, ans = N + 1;

	while (right <= N) {
		if (sum >= S) {
			ans = min(ans, right - left);
			sum -= num[left++];
		}
		else {
			sum += num[right++];
		}
	}
	cout << ((ans == N + 1) ? 0 : ans);

	return 0;
}