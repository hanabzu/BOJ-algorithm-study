/* BOJ_4375 1 */
/* hanabzu */

#include <iostream>

using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n) {
		int num = 0;
		for (int i = 1; i <= n; i++) {
			num = num * 10 + 1;
			num %= n; // minus multi of n
			if (num == 0) {
				cout << i << '\n';
				break;
			}
		}
	}


	return 0;
}