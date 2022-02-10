/* BOJ_9527 1의 개수 세기 */
/* hanabzu */

#include <iostream>

using namespace std;

long long A, B;
long long sol(long long n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	cout << sol(B) - sol(--A);

	return 0;
}

long long sol(long long n) {
	long long ans = 0, exp = 1;
	for (int i = 1; exp <= n; i++) {
		ans += exp * (n >> i);
		if ((n & exp) == exp) {
			ans += n - ((n >> (i - 1)) << (i - 1)) + 1;
		}
		exp <<= 1;
	}
	return ans;

}