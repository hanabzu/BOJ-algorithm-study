/* BOJ_9935 문자열 폭발 */
/* hanabzu */

#include <iostream>

using namespace std;

const int MAXC = 1000000;

char s[MAXC + 1];
string table, bomb;
int p = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> table >> bomb;

	for (int i = 0; i < table.size(); i++) {

		s[p++] = table[i];
		
		if (p < bomb.size()) continue;

		for (int j = 0; j < bomb.size(); j++) {
			if (s[p - j - 1] != bomb[bomb.size() - j - 1]) {
				break;
			}
			if (j == bomb.size() - 1) {
				p -= bomb.size();
			}
		}

	}
	s[p] = '\0';
	
	if (p == 0) cout << "FRULA";
	else cout << s;

	return 0;
}