/* hanabzu* /
/* BOJ_11660 구간 합 구하기 5 */

#include <iostream>

using namespace std;

int matrix[1025][1025] = { 0, };
int N, M, num, x_one, y_one, x_two, y_two;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			matrix[i][j] = num - matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i][j - 1];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x_one >> y_one >> x_two >> y_two;
		x_one--; y_one--;
		num = matrix[x_two][y_two];
		num -= (matrix[x_one][y_two] + matrix[x_two][y_one]);
		num += matrix[x_one][y_one];
		cout << num << '\n';
	}

	return 0;
}