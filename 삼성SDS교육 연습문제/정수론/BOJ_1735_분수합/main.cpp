/* BOJ_1735 분수 합 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int ax, bx, ay, by, c, rx, ry;

int main() {

	cin >> ay >> ax >> by >> bx;

	ry = ay * bx + by * ax;
	rx = ax * bx;
	c = gcd(ry, rx); // c++ 17

	cout << ry / c << ' ' << rx / c;

	return 0;
}