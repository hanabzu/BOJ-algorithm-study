/* BOJ_3425 고스택 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXV 1000000000

enum INST {
	NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD
};

void machine(string inst);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string inst;
	while (1) {
		cin >> inst;
		if (inst == "QUIT") {
			break;
		}
		else {
			machine(inst);
		}
		cout << '\n';
	}



	return 0;
}


void machine(string inst) {
	bool is_error = false;
	int stack[1000];
	int N, temp, top = -1, num_top = 0;
	vector<int> insts;
	vector<int> num_insts;

	while (inst != "END") {
		if (inst == "NUM") {
			insts.push_back(NUM);
			cin >> temp;
			num_insts.push_back(temp);
		}
		else if (inst=="POP") {
			insts.push_back(POP);
		}
		else if (inst == "INV") {
			insts.push_back(INV);
		}
		else if (inst == "DUP") {
			insts.push_back(DUP);
		}
		else if (inst == "SWP") {
			insts.push_back(SWP);
		}
		else if (inst == "ADD") {
			insts.push_back(ADD);
		}
		else if (inst == "SUB") {
			insts.push_back(SUB);
		}
		else if (inst == "MUL") {
			insts.push_back(MUL);
		}
		else if (inst == "DIV") {
			insts.push_back(DIV);
		}
		else {
			insts.push_back(MOD);
		}
		cin >> inst;
	}


	cin >> N;

	for (int i = 0; i < N; i++) {
		is_error = false;
		num_top = 0;
		top = 0;
		cin >> stack[0];

		for (vector<int>::iterator it = insts.begin(); it != insts.end(); it++) {
			if (*it == NUM) {
				stack[++top] = num_insts[num_top++];
			}
			else if (*it == POP) {
				if (top < 0) {
					is_error = true;
					break;
				}
				top--;
			}
			else if (*it == INV) {
				if (top < 0) {
					is_error = true;
					break;
				}
				stack[top] = -stack[top];
			}
			else if (*it == DUP) {
				if (top < 0) {
					is_error = true;
					break;
				}
				stack[top + 1] = stack[top];
				top++;
			}
			else if (*it == SWP) {
				if (top < 1) {
					is_error = true;
					break;
				}
				swap(stack[top], stack[top - 1]);
			}
			else if (*it == ADD) {
				if (top < 1 || abs(stack[top] + stack[top - 1])>MAXV) {
					is_error = true;
					break;
				}

				temp = stack[top] + stack[top - 1];
				top--;
				stack[top] = temp;

			}
			else if (*it == SUB) {
				if (top < 1 || abs(stack[top - 1] - stack[top])>MAXV) {
					is_error = true;
					break;
				}
				temp = stack[top - 1] - stack[top];
				top--;
				stack[top] = temp;
			}
			else if (*it == MUL) {
				if (top < 1) {
					is_error = true;
					break;
				}
				long long t = ((long long)stack[top - 1]) * ((long long)stack[top]);
				if (abs(t) > MAXV) {
					is_error = true;
					break;
				}
				top--;
				stack[top] = t;
			}
			else if (*it == DIV) {
				if (top < 1 || stack[top] == 0) {
					is_error = true;
					break;
				}
				temp = abs(stack[top - 1]) / abs(stack[top]);
				if ((stack[top] < 0) ^ (stack[top - 1] < 0)) {
					temp = -temp;
				}
				top--;
				stack[top] = temp;
			}
			else {
				if (top < 1 || stack[top] == 0) {
					is_error = true;
					break;
				}

				temp = abs(stack[top - 1]) % abs(stack[top]);
				if (stack[top-1] < 0) {
					temp = -temp;
				}
				top--;
				stack[top] = temp;
			}
		}

		if (top != 0 || is_error) {
			cout << "ERROR\n";
		}
		else {
			cout << stack[top] << '\n';
		}
	}


}