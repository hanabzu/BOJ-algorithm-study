/* BOJ_14890 경사로 */
/* hanabzu */

#include <iostream>
#include <string.h>

using namespace std;

const int MAXN = 100;
int N, L, ans = 0;
int n[MAXN][MAXN], t[MAXN];

bool isRoad();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		memcpy(t, n[i], sizeof(t));
		if (isRoad()) ans++;
		for (int j = 0; j < N; j++) {
			t[j] = n[j][i];
		}
		if (isRoad()) ans++;
	}

	cout << ans;


	return 0;
}

bool isRoad() {
	bool runway[MAXN] = { 0, };
	int prev = t[0], pos;
	for (int i = 1; i < N; i++) {
		if (t[i] == prev) continue;

		if (t[i] == prev + 1) {
			for (int k = 0; k < L; k++) {
				pos = i - 1 - k;
				if (pos < 0 || t[pos] != prev || runway[pos]) { // can't use
					return false;
				}
				else {
					runway[pos] = true;
				}
			}
		}
		else if (t[i] == prev - 1) {
			for (int k = 0; k < L; k++) {
				pos = i + k;
				if (pos >= N || t[pos] != t[i] || runway[pos]) { // can't use
					return false;
				}
				else {
					runway[pos] = true;
				}
			}
		}
		else {
			return false;
		}
		prev = t[i];
	}
	return true;
}