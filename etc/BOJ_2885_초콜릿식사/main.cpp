/* BOJ_2885 초콜릿 식사 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

int K, choco, cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (choco = 1; choco < K; choco <<= 1);

	int t = choco;
	
	if (K != choco) {
		while (K > 0) {
			if (K - t >= 0) {
				K -= t;
				if (K == 0) break;
			}
			t >>= 1;
			cnt++;
		}
	}

	


	cout << choco << ' ' << cnt;

	return 0;
}