/* BOJ_2473 세 용액 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
const long long MAXA = 3000000001;
const int MAXN = 5000;
int N, lhs, rhs, a, b, c;
long long ph, min_ph = MAXA;
long long n[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> n[i];
	sort(n, n + N);

	for (int i = 0; i < N; i++) {
		lhs = i + 1;
		rhs = N - 1;
		while (lhs < rhs) {
			ph = n[i] + n[lhs] + n[rhs];
			if (abs(ph) < min_ph) {
				min_ph = abs(ph);
				c = n[i];
				a = n[lhs];
				b = n[rhs];
			}
			if (ph == 0) {
				break;
			}
			if (ph < 0) {
				lhs++;
			}
			else {
				rhs--;
			}
		}
	}


	cout << c << ' ' << a << ' ' << b;

	return 0;
}