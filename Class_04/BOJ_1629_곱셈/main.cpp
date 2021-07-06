/* hanabzu */
/* BOJ_1629 곱셈 */

#include <iostream>
#include <bitset>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned int A, B, C;
	unsigned long long r = 1;
	unsigned long long table[33];
	cin >> A >> B >> C;
	table[0] = A % C;
	for (int i = 1; i < 32; i++) {
		table[i] = (table[i - 1] * table[i - 1]) % C;
	}
	bitset<32> Bbit = bitset<32>(B);

	for (int i = 0; i < 32; i++) { // divide and conquer
		if (Bbit[i] == 1) {
			r = (r * table[i]) % C;
		}
	}
	cout << r;
	return 0;
}