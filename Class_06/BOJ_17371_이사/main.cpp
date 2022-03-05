/* BOJ_17371 이사 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
using namespace std;

const int MAXN = 1000;
int N;
pair<double, double> dot[MAXN];
double d[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> dot[i].first >> dot[i].second;
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			d[i] = max(d[i], pow(dot[i].first - dot[j].first, 2) + pow(dot[i].second - dot[j].second, 2));
		}
	}

	int ans = min_element(d, d + N) - d;

	cout << dot[ans].first << ' ' << dot[ans].second;

	return 0;
}