/* BOJ_2096 내려가기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int window[3];
int dp_max[3], dp_min[3];
int v_max[3], v_min[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	// dynamic summation
	for (int i = 0; i < N; i++) {
		cin >> window[0] >> window[1] >> window[2];

		v_max[0] = window[0] + max(dp_max[0], dp_max[1]);
		v_max[1] = window[1] + *max_element(dp_max, dp_max + 3);
		v_max[2] = window[2] + max(dp_max[1], dp_max[2]);

		v_min[0] = window[0] + min(dp_min[0], dp_min[1]);
		v_min[1] = window[1] + *min_element(dp_min, dp_min + 3);
		v_min[2] = window[2] + min(dp_min[1], dp_min[2]);

		for (int j = 0; j < 3; j++) {
			dp_max[j] = v_max[j];
			dp_min[j] = v_min[j];
		}
	}

	cout << *max_element(v_max, v_max + 3) << ' ';
	cout << *min_element(v_min, v_min + 3);
	return 0;
}