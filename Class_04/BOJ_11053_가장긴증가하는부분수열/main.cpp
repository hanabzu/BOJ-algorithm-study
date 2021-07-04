/* hanabzu */
/* BOJ_11053 가장 긴 증가하는 부분 수열 */

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000];
int len[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		len[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				len[i] = max(len[i], len[j] + 1);
			}
		}
	}
	cout << *max_element(len, len + N);

	return 0;
}