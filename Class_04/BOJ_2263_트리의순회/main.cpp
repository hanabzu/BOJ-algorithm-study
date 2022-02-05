/* BOJ_2263 트리의 순회 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXN = 100000;
int in_order[MAXN + 1], post_order[MAXN + 1], index[MAXN + 1];
int n;

void pre(int size, int in_idx, int post_idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> in_order[i];
		index[in_order[i]] = i;
	}
	for (int i = 1; i <= n; i++) cin >> post_order[i];

	pre(n, 1, 1);

	return 0;
}

void pre(int size, int in_idx, int post_idx) {
	if (size == 0) return;

	int root = post_order[post_idx + size - 1];

	cout << root << ' ';

	int left_size = index[root] - in_idx;

	pre(left_size, in_idx, post_idx);
	pre(size - left_size - 1, in_idx + left_size + 1, post_idx + left_size);
}