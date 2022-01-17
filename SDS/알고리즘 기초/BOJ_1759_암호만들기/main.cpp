/* BOJ_1759 암호 만들기 */
/* hanabzu */

#include <iostream>
#include <bitset>
using namespace std;

char c;
int L, C;
string table = "abcdefghijklmnopqrstuvwxyz";
bitset<26> CC, B, vowel, consonant;
int aeiou[5] = { 0,4,8,14,20 };

void back_track(int p, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// set aeiou
	consonant.set();
	for (int i = 0; i < 5; i++) {
		vowel.set(aeiou[i]);
		consonant.reset(aeiou[i]);
	}

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> c;
		CC.set(c - 'a');
	}
	back_track(0, 0);

	return 0;
}

void back_track(int p, int depth) {
	if (depth == L && (B & vowel).any() && (B & consonant).count() >= 2) {
		for (int i = 0; i < 26; i++) {
			if (B[i]) cout << table[i];
		}
		cout << '\n';
		return;
	}

	for (int i = p; i < 26; i++) {
		if (CC[i]) {
			B.set(i);
			back_track(i+1, depth + 1);
			B.reset(i);
		}
	}
}