/* BOJ_1708 볼록 껍질 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
const int INF = 987654321;
struct Point {
	long long x, y;
	long long p = 1, q = 0;
	Point() {}
	Point(long long x, long long y) :x(x), y(y) {}
};

int N, top = 0, stack[MAXN];
Point point[MAXN];
int ccw(Point& A, Point& B, Point& C);
bool comp(Point& A, Point& B);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> point[i].x >> point[i].y;
	}

	sort(point, point + N, comp);
	for (int i = 1; i < N; i++) {
		point[i].p = point[i].x - point[0].x;
		point[i].q = point[i].y - point[0].y;
	}

	sort(point + 1, point + N, comp);

	stack[++top] = 0;
	stack[++top] = 1;
	int next = 2, first, second;
	while (next < N) {
		while (top >= 2) {
			second = stack[top--];
			first = stack[top];
			if (ccw(point[first], point[second], point[next]) > 0) {
				stack[++top] = second;
				break;
			}
		}
		stack[++top] = next++;
	}

	cout << top;
	return 0;
}

int ccw(Point& A, Point& B, Point& C) {
	long long s = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool comp(Point& A, Point& B) {
	if (A.q * B.p != A.p * B.q) return A.q * B.p < A.p* B.q;
	if (A.y != B.y) return A.y < B.y;
	return A.x < B.x;
}