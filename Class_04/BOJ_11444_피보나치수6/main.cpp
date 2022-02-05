/* BOJ_11444 피보나치 수 6 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MOD = 1000000007;

struct Mat {
	long long x0y0, x1y0, x0y1, x1y1;
	Mat(long long x0y0, long long x1y0, long long x0y1, long long x1y1) :
		x0y0(x0y0), x1y0(x1y0), x0y1(x0y1), x1y1(x1y1) {}
	Mat() {}
};

long long n;
Mat F(1, 1, 1, 0);

Mat cal(Mat A, long long n);
Mat multi(Mat A, Mat B);

int main() {
	
	cin >> n;

	Mat R = cal(F, n);

	cout << R.x0y1;
	return 0;
}

Mat cal(Mat A, long long n) {
	if (n > 1) {
		A = cal(A, n >> 1);
		A = multi(A, A);
		if ((n & 1) == 1) {
			A = multi(A, F);
		}
	}
	return A;
}

Mat multi(Mat A, Mat B) {
	Mat C;
	C.x0y0 = ((A.x0y0 * B.x0y0) + (A.x0y1 * B.x1y0)) % MOD;
	C.x0y1 = ((A.x0y0 * B.x0y1) + (A.x0y1 * B.x1y1)) % MOD;
	C.x1y0 = ((A.x1y0 * B.x0y0) + (A.x1y1 * B.x1y0)) % MOD;
	C.x1y1 = ((A.x1y0 * B.x0y1) + (A.x1y1 * B.x1y1)) % MOD;
	return C;
}