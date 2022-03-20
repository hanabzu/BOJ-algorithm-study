/* hanabzu */
/* BOJ_2579 계단 오르기 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int* score = new int[n];
	int* total[3];
	total[0] = new int[n]; // end with no step
	total[1] = new int[n]; // end with one step
	total[2] = new int[n]; // end with double step

	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	total[0][0] = 0;
	total[1][0] = total[2][0] = score[0];

	for (int i = 1; i < n; i++) {
		total[0][i] = max(total[1][i - 1], total[2][i - 1]);

		total[1][i] = total[0][i - 1] + score[i];

		total[2][i] = total[1][i - 1] + score[i];
	}

	cout << max(total[1][n - 1], total[2][n - 1]);

	delete[] score;
	delete[] total[0];
	delete[] total[1];
	delete[] total[2];
	return 0;
}