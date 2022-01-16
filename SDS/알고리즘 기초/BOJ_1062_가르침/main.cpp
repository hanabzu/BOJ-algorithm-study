/* BOJ_1062 가르침 */
/* hanabzu */

#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int antatica[5] = { 0, 2, 8, 13, 19 };
int N, K, max_n = 0;
string s;
bitset<26> table;
vector<bitset<26>> words;
void backtrack(int depth, int idx);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < 5; i++) {
		table.set(antatica[i]);
	}

	for (int i = 0; i < N; i++) {
		cin >> s;
		bitset<26> new_word = table;
		for (int c = 4; c < s.size() - 4; c++) {
			new_word.set(s[c] - 'a');
		}
		words.push_back(new_word);
	}
	K -= 5;
	backtrack(0, 0);
	cout << max_n;

	return 0;
}

void backtrack(int depth, int idx) {
	if (depth > K) {
		return;
	}
	int n = 0;
	for (vector<bitset<26>>::iterator it = words.begin(); it != words.end(); it++) {
		if ((table | *it) == table) {
			n++;
		}
	}

	max_n = max(max_n, n);

	for (int i = idx; i < 26; i++) {
		if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19) {
			i++;
		}
		table.set(i);
		backtrack(depth + 1, i + 1);
		table.reset(i);
	}
}