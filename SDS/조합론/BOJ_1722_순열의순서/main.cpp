/* BOJ_1722 순열의 순서 */
/* hanabzu */

#include <iostream>
#define MAXN 20

using namespace std;

int N, M;
long long K;
long long f[MAXN + 1];
int n[MAXN];
bool visit[MAXN + 1];

void prob_one();
void prob_two();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	f[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = i * f[i - 1];
	}

	if (M == 1) {
		prob_one();
	}
	else {
		prob_two();
	}

	return 0;
}

void prob_one() {
	cin >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[j]) continue;

			if (K <= f[N - i - 1]) {
				cout << j << ' ';
				visit[j] = true;
				break;
			}
			else {
				K -= f[N - i - 1];
			}
		}
	}
}

void prob_two() {
	long long ans = 1;

	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < n[i]; j++) {
			if (visit[j]) continue;
			ans += f[N - i - 1];
		}
		visit[n[i]] = true;
	}
	cout << ans;
}