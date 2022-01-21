/* BOJ_3020 개똥벌레 */
/* hanabzu */

#include <iostream>
#define MAXN 200000
#define MAXH 500000
using namespace std;

int N, H;
int ob[MAXH + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> H;
	N >>= 1;
	for (int i = 0, d, u; i < N; i++) {
		cin >> d >> u;
		ob[0]++;
		ob[d]--;
		ob[H - u]++;
	}

	int num = 1;
	int min_ans = MAXN + 1;

	int now_ans = 0;
	for (int i = 0; i < H; i++) {
		now_ans += ob[i];
		if (now_ans < min_ans) {
			min_ans = now_ans;
			num = 1;
		}
		else if (now_ans == min_ans) {
			num++;
		}
	}

	cout << min_ans << ' ' << num;
	return 0;
}