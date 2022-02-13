/* BOJ_16724 피리 부는 사나이 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 1000;

struct Point {
	int r = -1, c = -1;
	Point(int r, int c) :r(r), c(c) {}
	Point() {}
	friend bool operator==(Point lhs, Point rhs) {
		return (lhs.r == rhs.r) && (lhs.c == rhs.c);
	}
};

int N, M, ans = 0;
Point parent[MAXN][MAXN];
string map[MAXN];

void uni(Point& a, Point& b);
Point find(Point& a);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			parent[i][j] = Point(i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Point lhs = Point(i, j), rhs;
			switch (map[i][j]) {
			case 'L':
				rhs = Point(i, j - 1);
				break;
			case 'R':
				rhs = Point(i, j + 1);
				break;
			case 'U':
				rhs = Point(i - 1, j);
				break;
			case 'D':
				rhs = Point(i + 1, j);
			}
			if (find(lhs) == find(rhs)) {
				ans++;
			}
			else {
				uni(lhs, rhs);
			}
		}
	}

	cout << ans;
	return 0;
}

void uni(Point& a, Point& b) {
	Point pa = find(a);
	Point pb = find(b);
	parent[pa.r][pa.c] = pb;
}

Point find(Point& a) {
	if (parent[a.r][a.c] == a) {
		return a;
	}
	else {
		return parent[a.r][a.c] = find(parent[a.r][a.c]);
	}
}