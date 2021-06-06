/* hanabzu */
/* BOJ_1620 나는야 포켓몬 마스터 이다솜 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

string* num_dic; // dictionary sorted by index
map<string, int> name_dic; // dictionary sorted alphabetically

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string A; // for input
	cin >> N >> M;

	num_dic = new string[N];

	// read data
	for (int i = 0; i < N; i++) {
		cin >> A;
		num_dic[i] = A;
		name_dic[A] = i;
	}

	// print
	for (int i = 0; i < M; i++) {
		cin >> A;
		if (atoi(A.c_str())== 0) { // find by name
			cout << name_dic[A] + 1 << '\n';
		}
		else { // find by index
			cout << num_dic[stoi(A) - 1] << '\n';
		}
	}
}