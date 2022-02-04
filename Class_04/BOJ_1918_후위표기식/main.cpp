/* BOJ_1918 후위 표기식 */
/* hanabzu */

#include <iostream>
#include <ctype.h>

using namespace std;

int p = 0;
int top = 0;
char stack[100];
string s;
int order(char op);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	stack[0] = '$'; // end
	while (p < s.size()) {
		if (s[p] == '(') {
			stack[++top] = '(';
		}
		else if (isalpha(s[p])) {
			cout << s[p];
		}
		else if (s[p] == ')') {
			while (stack[top] != '(') {
				cout << stack[top--];
			}
			top--; // pop '('
		}
		else {
			if (order(s[p]) > order(stack[top])) {
				stack[++top] = s[p];
			}
			else {
				cout << stack[top--];
				continue;
			}
		}
		p++;
	}
	while (top > 0) {
		cout << stack[top--];
	}

	return 0;
}

int order(char op) {
	switch (op) {
	case '$':
		return 0;
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	}
}
