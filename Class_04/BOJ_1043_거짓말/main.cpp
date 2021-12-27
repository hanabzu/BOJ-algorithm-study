/* BOJ_1042 거짓말 */
/* hanabzu */

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int N, M, T, a, b, result = 0;
bitset<51> T_set, temp;
vector<bitset<51>> party;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 0; i < T; i++) {
		cin >> a;
		T_set.set(a);
	}

	for (int i = 0; i < M; i++) {
		cin >> a;
		party.push_back(bitset<51>());
		for (int j = 0; j < a; j++) {
			cin >> b;
			party[i].set(b);
		}
	}

	 do {
		temp = T_set;
		for (vector<bitset<51>>::iterator it = party.begin(); it != party.end(); it++) {
			if (((*it) & T_set).any()) {
				T_set = (*it) | T_set;
			}
		}
	 } while (temp != T_set);


	 for (vector<bitset<51>>::iterator it = party.begin(); it != party.end(); it++) {
		 if (!((*it) & T_set).any()) {
			 result++;
		 }
	 }

	 cout << result;

	return 0;
}