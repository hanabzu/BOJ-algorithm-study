/* BOJ_11689 GCD(n,k) = 1 */
/* hanabzu */

#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

long long n, ans = 1;
map<long long, long long> m;
int main() {
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (long long i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			m[i]++;
		}
	}
	if (n != 1) m[n]++;

	for (map<long long, long long>::iterator it = m.begin(); it != m.end(); it++) {
		ans *= (static_cast<long long>(pow(it->first, it->second))
			- static_cast<long long>(pow(it->first, it->second - 1)));
	}

	cout << ans;
	return 0;
}