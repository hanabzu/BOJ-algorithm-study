/* BOJ_14476 최대공약수 하나 빼기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <numeric>
#define MAXN 1000000

using namespace std;

int N;
int num[MAXN + 1];
int left_gcd[MAXN + 1];
int right_gcd[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	left_gcd[0] = num[0];
	for (int i = 1; i < N; i++) {
		left_gcd[i] = gcd(left_gcd[i - 1], num[i]);
	}
	right_gcd[N - 1] = num[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		right_gcd[i] = gcd(right_gcd[i + 1], num[i]);
	}

	int out_num = num[0];
	int max_gcd = right_gcd[1];
	if (!(num[0] % max_gcd)) {
		out_num = 0;
		max_gcd = 0;
	}

	for (int i = 1; i < N; i++) {
		int temp_gcd = gcd(left_gcd[i - 1], right_gcd[i + 1]);

		if (num[i] % temp_gcd && temp_gcd > max_gcd) {
			max_gcd = temp_gcd;
			out_num = num[i];
		}

	}

	if (max_gcd == 0) {
		cout << -1;
	}
	else {
		cout << max_gcd << ' ' << out_num;
	}
	return 0;
}