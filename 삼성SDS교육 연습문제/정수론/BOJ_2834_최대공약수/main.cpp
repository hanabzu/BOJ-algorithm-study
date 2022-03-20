/* BOJ_2825 최대 공약수 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#define MOD 1000000000
#define MAXN 1000
using namespace std;

int N, M;
int n[MAXN], m[MAXN];
long long nn = 1, mm = 1;
bool isOver = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m[i];
	}

	long long g, nn = 1, mm = 1, ans = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			g = gcd(n[i], m[j]);
			n[i] /= g;
			m[j] /= g;

			ans = ans * g;
			if (ans >= MOD) {
				isOver = true;
				ans = ans % MOD;
			}
		}
	}

	if (isOver) {
		cout.width(9);
		cout.fill('0');
	}
	cout << ans;


	return 0;
}