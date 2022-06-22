/* BOJ_1786 찾기 */
/* hanabzu */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
vector<int> pi, ans;
void getPi();
void kmp();

int main() {
	getline(cin, T);
	getline(cin, P);
	
	getPi();
	kmp();
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << ' ';
	}

	return 0;
}

void getPi() {
	pi = vector<int>(P.size(), 0);

	int i = 1, j = 0;
	for (i = 1; i < P.size(); i++) {
		while (j > 0 && P[i] != P[j]) {
			j = pi[j - 1];
		}
		if (P[i] == P[j]) {
			pi[i] = ++j;
		}
	}
}

void kmp() {
	int i = 0, j = 0;
	for (i = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != P[j]) {
			j = pi[j - 1];
		}
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				ans.push_back(i - P.size() + 1);
				j = pi[j];
			} 
			else {
				j++;
			}
		}
	}
}