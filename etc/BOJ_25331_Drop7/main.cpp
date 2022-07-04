/* BOJ_25331 Drop 7 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
const int INF = 10000;

int K, map[7][7], cnt, hor[7], ver[7], pos[7], ans = INF;
int tmap[7][7], tcnt, top = -1;
pii stack[7];

bool isMatch[7][7];

void test_case(int ncol);
bool instruction();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(pos, pos + 7, -1);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				cnt++;
			}
			else {
				pos[j]++;
			}
		}
	}
	cin >> K;
	cnt++;

	for (int i = 0; i < 7; i++) {
		test_case(i);
	}
	cout << ans;
	return 0;
}

void test_case(int ncol) {
	memcpy(tmap, map, sizeof(map));
	tcnt = cnt;
	tmap[pos[ncol]][ncol] = K;

	while (instruction()) continue;

	ans = min(ans, tcnt);
}

bool instruction() {
	bool isBoom = false;
	memset(isMatch, false, sizeof(isMatch));

	for (int i = 0; i < 7; i++) {
		int lcnt = 0;
		top = -1;

		for (int j = 0; j < 8; j++) { // out of border -> empty stack
			if (j == 7 || tmap[i][j] == 0) {
				while (top > -1) {
					if (tmap[stack[top].first][stack[top].second] == lcnt) {
						isMatch[stack[top].first][stack[top].second] = true;
					}
					top--;
				}
				lcnt = 0;
			}
			else {
				lcnt++;
				stack[++top] = make_pair(i, j);
			}
		}

		lcnt = 0;
		top = -1;
		for (int j = 0; j < 8; j++) { // out of border -> empty stack
			if (j == 7 || tmap[j][i] == 0) {
				while (top > -1) {
					if (tmap[stack[top].first][stack[top].second] == lcnt) {
						isMatch[stack[top].first][stack[top].second] = true;
					}
					top--;
				}
				lcnt = 0;
			}
			else {
				lcnt++;
				stack[++top] = make_pair(j, i);
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (!isMatch[i][j]) continue;

			isBoom = true;
			tcnt--;
			tmap[i][j] = 0;
			for (int k = i - 1; k >= 0; k--) {
				if (tmap[k][j] > 0) swap(tmap[k][j], tmap[k + 1][j]);
			}
		}
	}

	return isBoom;
}