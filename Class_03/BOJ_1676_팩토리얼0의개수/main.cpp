/* hanabzu */
/* BOJ_1676 팩토리얼 0의 개수 */

#include <iostream>

using namespace std;
int count(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p, q;

	cin >> n;

	cout << count(n);
}

int count(int n) { // count numbers of prime factor 2, 5
	int p, q, numTwo = 0, numFive = 0;

	for (int i = 1; i <= n; i++) {
		p = q = i;
		while (p % 2 == 0) {
			numTwo++;
			p = p >> 1;
		}
		while (q % 5 == 0) {
			numFive++;
			q = q / 5;
		}
	}
	return (numTwo < numFive ? numTwo : numFive);
}
