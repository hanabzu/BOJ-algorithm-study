/* BOJ_12850 본대 산책 2 */
/* hanabzu */

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;
const ll MOD = 1000000007;

// 정보과학관, 전산관, 미래관, 신양관, 한경직기념관, 진리관, 학생회관, 형남공학관
vll e = { {0, 1, 1, 0, 0, 0, 0, 0 },
		  {1, 0, 1, 1, 0, 0, 0, 0 },
		  {1, 1, 0, 1, 1, 0, 0, 0 },
		  {0, 1, 1, 0, 1, 1, 0, 0 },
		  {0, 0, 1, 1, 0, 1, 0, 1 },
		  {0, 0, 0, 1, 1, 0, 1, 0 },
		  {0, 0, 0, 0, 0, 1, 0, 1 },
		  {0, 0, 0, 0, 1, 0, 1, 0 } };
int D;
vll d;
vll cal(vll& e, int n);
vll multiply(vll& a, vll& b);

int main() {
	cin >> D;
	d = e;
	cal(e, D);
	cout << e[0][0];

	return 0;
}

vll cal(vll& e, int n) {
	if (n > 1) {
		e = cal(e, n >> 1);
		e = multiply(e, e);
		if ((n & 1) == 1) {
			e = multiply(e, d);
		}
	}
	return e;
}

vll multiply(vll& a, vll& b) {
	vll newm(8, vector<ll>(8));
	ll tmp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tmp = 0;
			for (int k = 0; k < 8; k++) {
				tmp = (tmp + (a[i][k] * b[k][j])) % MOD;
			}
			newm[i][j] = tmp;
		}
	}
	return newm;
}