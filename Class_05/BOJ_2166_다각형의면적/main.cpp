/* BOJ_2166 다각형의 면적 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 10000;

int N;
double x[MAXN + 1], y[MAXN + 1];
double S;

void get_area(int i);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	x[N] = x[0];
	y[N] = y[0];
	for (int i = 0; i < N; i++) {
		get_area(i);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(S/2.0);
	return 0;
}

void get_area(int i) {
	double dx = x[i + 1] - x[i], dy = y[i] + y[i + 1];
	double flag;
	if (dx > 0) {
		flag = 1.0;
	}
	else {
		flag = -1.0;
		dx = -dx;
	}

	S += dx * dy * flag;
}