/* BOJ_2467 용액 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXA = 1000000000;
const int MAXN = 100000;
int N, lhs, rhs, ph, min_ph = (MAXA << 1) + 1, a, b;
int n[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> n[i];

	lhs = 0;
	rhs = N - 1;
	while (lhs < rhs) {
		ph = n[lhs] + n[rhs];
		if (abs(ph) < min_ph) {
			min_ph = abs(ph);
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
	
	cout << a << ' ' << b;

	return 0;
}
