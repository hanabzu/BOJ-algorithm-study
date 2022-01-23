/* BOJ_6588 골드바흐의 추측 */
/* hanabzu */

#include <iostream>
#include <vector>
#define MAXN 4000000

using namespace std;

int N;
bool visit[MAXN + 1];
vector<int> p;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int s = 2; s <= N; s++) {
		if (!visit[s]) {
			int i = s << 1;
			while (i <= N) {
				if (!visit[i]) {
					visit[i] = true;
				}
				i += s;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!visit[i]) p.push_back(i);
	}
	p.push_back(MAXN+1); // dead
	int cnt = 0;
	int l = 0, r = 0;
	int s = p[l];
	while (s) { // two pointers
		if (s == N) {
			cnt++;
			s -= p[l];
			l++;
		}
		else if (s < N) {
			r++;
			s += p[r];
		}
		else {
			s -= p[l];
			l++;
		}
	}
	cout << cnt;

	return 0;
}