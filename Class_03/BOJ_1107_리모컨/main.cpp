/* hanabzu */
/* BOJ_1107 리모컨 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

string N, x;
int num, M;
set<string> deck;
set<int> candidate;

void makeNum(string s, int digit, string d);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		deck.insert(to_string(i));
	}

	cin >> N >> M;

	num = stoi(N);
	for (int i = 0; i < M; i++) { // delete from deck
		cin >> x;
		deck.erase(x);
	}

	int hard = abs(num - 100);

	for (int i = N.length() - 1; i <= N.length() + 1; i++) { // brute force
		if (i > 0 && i < 7) {
			for (set<string>::iterator it = deck.begin(); it != deck.end(); it++) {
				string s = "";
				makeNum(s, i, *it);
			}
		}
	}
	if (candidate.empty()) {
		cout << hard;
	}
	else {
		int soft = *candidate.begin();
		if (hard <= soft) {
			cout << hard;
		}
		else {
			cout << soft;
		}
	}
	return 0;
}

void makeNum(string s, int digit, string d) { // find all numbers
	s += d;
	digit--;
	if (digit == 0) {
		candidate.insert(abs(stoi(s)-num) + s.size());
	}
	else {
		for (set<string>::iterator it = deck.begin(); it != deck.end(); it++) {
			makeNum(s, digit, *it);
		}
	}
}