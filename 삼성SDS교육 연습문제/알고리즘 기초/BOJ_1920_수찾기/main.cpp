/* BOJ_1920 수 찾기 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#define MAXN 100000

using namespace std;
int N, M, target;
int arr[MAXN + 1];

bool binary_search(int l, int r);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> target;
		cout << binary_search(-1, N - 1) << '\n';
	}
	return 0;

}


bool binary_search(int l, int r) {
	int m;
	while (l + 1 < r) {
		m = l + ((r - l) >> 1);
		if (arr[m] < target) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return arr[r] == target ? true : false;
}