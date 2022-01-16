/* BOJ_2748 피보나치 수 2 */
/* hanabzu */

#include <iostream>

using namespace std;

int n;
long long mem[91];

long long fib(int n);

int main() {
	cin >> n;
	mem[1] = 1;
	cout << fib(n);

	return 0;
}


long long fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (mem[n] > 0) {
		return mem[n];
	}

	mem[n] += fib(n - 1) + fib(n - 2);
	return mem[n];

}