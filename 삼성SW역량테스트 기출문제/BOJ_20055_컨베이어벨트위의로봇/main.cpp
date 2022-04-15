/* BOJ_20055 컨베이어 벨트 위의 로봇 */
/* hanabzu */

#include <iostream>
using namespace std;

const int MAXN = 100;

int N, K, A[MAXN << 1], ans = 0, zero = 0;
bool isRobot[MAXN << 1];
int sp, ep; // start point, end point
bool process();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < (N << 1); i++) {
		cin >> A[i];
	}
	sp = 0;
	ep = N - 1;

	while (process());

	cout << ans;

	return 0;
}

bool process() {
	ans++;
	sp = (sp - 1 + (N << 1)) % (N << 1);
	ep = (ep - 1 + (N << 1)) % (N << 1);

	if (isRobot[ep]) {
		isRobot[ep] = false;
	}

	int i = ep - 1, next;
	while (i != sp) {
		next = (i == (N << 1) - 1) ? 0 : i + 1;
		if (isRobot[i] && !isRobot[next] && A[next]) {
			isRobot[i] = false;
			if (i + 1 != ep) isRobot[next] = true;
			if ((--A[next]) == 0) zero++;
		}
		if (--i < 0) i = (N << 1) - 1;
	}

	if (A[sp]) {
		isRobot[sp] = true;
		if ((--A[sp]) == 0) zero++;
	}

	return zero < K;
}