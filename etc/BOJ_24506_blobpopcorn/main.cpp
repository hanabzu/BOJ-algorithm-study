/* BOJ_24506 blobpopcorn */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 100000;
const int POWN = 18;
int N, Q, B, q, x, y, m;

pair<int, int> w_l[1 << POWN]; // lx가 존재하지 않는 x의 개수 LIS
pair<int, int> w_r[1 << POWN]; // rx가 존재하지 않는 x의 개수 LIS

void init();
void update(int p, int c);
int count_num(int p, pair<int, int>(&w)[1 << POWN]);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	for (B = 1; B < N; B <<= 1);

	for (int i = B; i < B + N; i++) {
		cin >> w_l[i].first;
		w_l[i].second = 1;
		w_r[(B << 1) + N - i - 1] = w_l[i];
	}

	init();
	
	while (Q--) {
		cin >> q;
		if (q == 1) {
			cin >> x >> y;
			update(x, y);
		}
		else {
			cout << (N << 1) - w_l[1].second - w_r[1].second << '\n';
		}
	}

	return 0;
}


void init() {
	for (int i = B - 1; i > 0; i--) {
		if (w_l[i << 1].first < w_l[(i << 1) | 1].first) {
			w_l[i] = w_l[(i << 1) | 1];
			m = w_l[i << 1].first;
			w_l[i].second = w_l[i << 1].second + count_num((i << 1) | 1, w_l);
		}
		else {
			w_l[i] = w_l[i << 1];
		}

		if (w_r[i << 1].first < w_r[(i << 1) | 1].first) {
			w_r[i] = w_r[(i << 1) | 1];
			m = w_r[i << 1].first;
			w_r[i].second = w_r[i << 1].second + count_num((i << 1) | 1, w_r);
		}
		else {
			w_r[i] = w_r[i << 1];
		}
	}
}

void update(int p, int c) {
	int lp = p + B - 1;
	int rp = B + N - p;

	w_l[lp].first = w_r[rp].first = c;

	while (lp >>= 1) {
		if (w_l[lp << 1].first < w_l[(lp << 1) | 1].first) {
			w_l[lp] = w_l[(lp << 1) | 1];
			m = w_l[lp << 1].first;
			w_l[lp].second = w_l[lp << 1].second + count_num((lp << 1) | 1, w_l);
		}
		else {
			w_l[lp] = w_l[lp << 1];
		}
	}

	while (rp >>= 1) {
		if (w_r[rp << 1].first < w_r[(rp << 1) | 1].first) {
			w_r[rp] = w_r[(rp << 1) | 1];
			m = w_r[rp << 1].first;
			w_r[rp].second = w_r[rp << 1].second + count_num((rp << 1) | 1, w_r);
		}
		else {
			w_r[rp] = w_r[rp << 1];
		}
	}
}

int count_num(int p, pair<int, int>(&w)[1 << POWN]) {
	int cnt;
	if (w[p].second == 1) {
		return (w[p].first > m) ? 1 : 0;
	}
	if (w[p << 1].first > m) {
		cnt = w[p].second - w[p << 1].second;
		return cnt + count_num(p << 1,  w);
	}
	else { // w[p << 1].first < m
		return count_num((p << 1)|1, w);
	}
	
}
