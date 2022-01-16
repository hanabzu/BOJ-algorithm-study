/* BOJ_2003 수들의 합 2 */
/* hanabzu */

#include <iostream>

using namespace std;

int N, M, cnt = 0;
int num[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (num[j] - num[i] == M) {
				cnt++;
			}
		}
	}

	cout << cnt;


	return 0;
}