/* hanabzu */
/* BOJ_1541 잃어버린 괄호 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input, token = "";
	int result = 0;
	bool minus = false;

	cin >> input;

	for (int i = 0; i < input.size()+1; i++) {
		if (isdigit(input[i])) {
			token += input[i];
		}
		else {
			if (minus) {
				result -= stoi(token);
			}
			else { // minus == false
				if(input[i] == '-') {
					minus = true;
				}
				result += stoi(token);
			}
			token = "";
		}
	}

	cout << result;

	return 0;

}