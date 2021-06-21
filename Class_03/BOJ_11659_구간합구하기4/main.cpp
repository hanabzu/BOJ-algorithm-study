/* hanabzu */
/* BOJ_11659 구간 합 구하기 4 */

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i, j;
	int* num;

	cin >> N >> M;

	num = new int[N+1];
	num[0] = 0;

	for (int k = 1; k < N+1; k++) {
		cin >> num[k];
		num[k] += num[k - 1];
	}

	for (int k = 0; k < M; k++) {
		cin >> i >> j;
		cout << num[j] - num[--i] << '\n';
	}

	return 0;
}