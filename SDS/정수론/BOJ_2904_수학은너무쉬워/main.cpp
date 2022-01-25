/* BOJ_2904 수학은 너무 쉬워 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAXN 1000000
using namespace std;

int N;
int n[100];
bool visit[MAXN + 1];
vector<int> p;
vector<vector<int>> np;
int pnum[MAXN];
int maxn = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n[i];
		maxn = max(maxn, n[i]);
	}
	for (int s = 2; s <= maxn; s++) {
		if (!visit[s]) {
			int i = s << 1;
			while (i <= maxn) {
				if (!visit[i]) {
					visit[i] = true;
				}
				i += s;
			}
		}
	}

	for (int i = 2; i <= maxn; i++) {
		if (!visit[i]) p.push_back(i);
	}


	for (int i = 0; i < N; i++) {
		vector<int> t;
		for (int j = 0; j < p.size(); j++) {
			int num = 0;
			while (n[i] % p[j] == 0) {
				num++;
				n[i] /= p[j];
			}
			t.push_back(num);
			pnum[j] += num;
		}
		np.push_back(t);
	}

	int score = 1, cnt = 0;

	for (int i = 0; i < p.size(); i++) {
		if (pnum[i] > 0) {
			int div = pnum[i] / N;
			if (div > 0) {
				score *= pow(p[i], div);
				for (int j = 0; j < N; j++) {
					if (np[j][i] < div) {
						cnt += div - np[j][i];
					}
				}
			}
		}
	}

	cout << score << ' ' << cnt;
	return 0;
}