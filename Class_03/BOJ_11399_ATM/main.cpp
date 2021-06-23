/* hanabzu */
/* BOJ_11399 ATM */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t, total;
	cin >> n;
	int time[1000];

	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}

	sort(time, time + n);

	total = time[0];
	for (int i = 1; i < n; i++) {
		time[i] += time[i-1];
		total += time[i];
	}

	cout << total;
}