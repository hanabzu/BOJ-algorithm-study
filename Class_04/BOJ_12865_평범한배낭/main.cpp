/* hanabzu */
/* BOJ_12865 평범한 배낭 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

int items[2][101];
int table[101][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> items[0][i] >> items[1][i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (items[0][i] <= j) {
				table[i][j] = max(table[i - 1][j], items[1][i] + table[i - 1][j - items[0][i]]);
			}
			else {
				table[i][j] = table[i - 1][j];
			}
		}
	}

	cout << table[N][K];

	return 0;
}