/* BOJ_1072 게임 */
/* hanabzu */

#include <iostream>
#define MAXX 1000000000

using namespace std;
long long X, Y, Z;
int l = 0, r = MAXX, m;
bool isChange(int m);

int main() {
	cin >> X >> Y;
	Z = Y*100 / X;
	if (Z > 98) {
		cout << -1;
	}
	else {
		while (l + 1 < r) {
			m = l + ((r - l) >> 1);
			if (isChange(m)) {
				r = m;
			}
			else {
				l = m;
			}
		}
		cout << r;
	}

	return 0;
}

bool isChange(int m) {
	if (Z < (Y + m) * 100 / (X + m))
		return true;
	else
		return false;
}