/* BOJ_4358 생태학 */
/* hanabzu */

#include <iostream>
#include <map>
#include <string>
using namespace std;

float total = 0, n;
string s;
map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (getline(cin,s)) {
		total++;
		if (m[s]) {
			m[s]++;
		}
		else {
			m[s] = 1;
		}
	}

	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		s = it->first;
		n = it->second;

		cout << s << ' ';
		cout << fixed;
		cout.precision(4);
		cout << n / total *100 << '\n';
	}

	return 0;
}