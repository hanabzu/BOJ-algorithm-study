/* BOJ_5376 소수를 분수로 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

int t;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> s;
		int i, a_size = 0, b_size = 0;
		long long a = 0, b = 0;
		for (i = 2; i < s.size(); i++) {
			if (s[i] == '(') break;
			a = a * 10 + s[i] - '0';
			a_size++;
		}
		b = a;
		for (i++; i < s.size(); i++) {
			if (s[i] == ')') break;
			b = b * 10 + s[i] - '0';
			b_size++;
		}

		long long n, m, g;
		if (b_size == 0) {
			n = a;
			m = pow(10, a_size);
		}
		else {
			n = b - a;
			m = pow(10, a_size + b_size) - pow(10, a_size);
		}
		g = gcd(n, m);
		cout << n / g << '/' << m / g << '\n';


	}

	return 0;
}