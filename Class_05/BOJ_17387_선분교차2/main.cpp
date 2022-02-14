/* BOJ_17387 선분 교차 2 */
/* hanabzu */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int x, y;
pair<int, int> dots[4];
bool isCrossed();
int ccw(int x1, int y1, int x2, int y2, int x3, int y3);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		dots[i] = make_pair(x, y);
	}
	cout << isCrossed();
	return 0;
}

bool isCrossed() {
	pair<int, int> a = dots[0];
	pair<int, int> b = dots[1];
	pair<int, int> c = dots[2];
	pair<int, int> d = dots[3];
	int ab = ccw(a.first, a.second, b.first, b.second, c.first, c.second) * ccw(a.first, a.second, b.first, b.second, d.first, d.second);
	int cd = ccw(c.first, c.second, d.first, d.second, a.first, a.second) * ccw(c.first, c.second, d.first, d.second, b.first, b.second);
	if (ab == 0 && cd == 0) {
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	long long s =((long long)(x2 - x1)) * (y3 - y1) - ((long long)(y2 - y1)) * (x3 - x1);
	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}