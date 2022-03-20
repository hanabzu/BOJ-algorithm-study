/* BOJ_13251 조약돌 꺼내기 */
/* hanabzu */

#include <iostream>
#define MAXM 50
using namespace std;

int M, K, N = 0;
int n[MAXM];
double ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> n[i];
		N += n[i];
	}
	cin >> K;

	for (int i = 0; i < M; i++) {
		if (n[i] < K) continue;
		double c = 1.0;
		for (int j = 0; j < K; j++) {
			c *= ((double)(n[i] - j) / (N - j));
		}
		ans += c;
	}
	cout.precision(15);
	cout << fixed <<ans;
	return 0;
}