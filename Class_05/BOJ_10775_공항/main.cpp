/* BOJ_10775 공항 */
/* hanabzu */

#include <iostream>
#include <algorithm>

using namespace std;

const int POWN = 18;
const int MAXG = 100000;

int idt[1 << POWN];
int G, P, B, g;

bool land(int c);
void update(int p, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> G >> P;
	
	for (B = 1; B < G; B <<= 1);

	fill(idt + B, idt + B + G, 1);

	for (int i = B - 1; i > 0; i--) {
		idt[i] = idt[i << 1] + idt[(i << 1) | 1];
	}

	int i;
	for (i = 0; i < P; i++) {
		cin >> g;
		if (!land(g)) {
			break;
		}
	}
	cout << i;

	return 0;
}
bool land(int p) {
	int lhs, rhs;
	p += (B - 1);
	do {
		if (idt[p] > 0) {
			break;
		}
		if ((p & (p - 1)) == 0) { // p is powers of 2
			return false;
		}
		if ((p & 1) == 1) { // p is odd
			p >>= 1;
		}
		else {
			p -= 1;
		}
	} while (p > 0);

	if (p == 0) {
		return false;
	}
	else {
		while (p < B) {
			lhs = p << 1;
			rhs = lhs + 1;
			if (idt[rhs] > 0) {
				p = rhs;
			}
			else {
				p = lhs;
			}
		} 
		update(p, -1);
		return true;
	}
}

void update(int p, int c) {
	do {
		idt[p] += c;
	} while (p >>= 1);
}
