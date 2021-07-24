/* hanabzu */
/* BOJ_10830 행렬제곱 */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int N;
unsigned long long B;

vector<vector<int>> multi_mat(const vector<vector<int>>& A, const vector<vector<int>>& B);
void print_mat(const vector<vector<int>>& mat);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> table[37], result;

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		result.push_back(vector<int>(N));
		table[0].push_back(vector<int>(N));
		for (int j = 0; j < N; j++) {
			cin >> table[0][i][j];
			if (i == j) { // initialize result matrix to identity matrix
				result[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i < 37; i++) { // binary table
		table[i] = multi_mat(table[i - 1], table[i - 1]);
	}

	bitset<37> Bbit = bitset<37>(B);
	for (int i = 0; i < 37; i++) {
		if (Bbit[i] == 1) {
			result = multi_mat(result, table[i]);
		}
	}

	print_mat(result);

	return 0;
}

vector<vector<int>> multi_mat(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	vector<vector<int>> res;

	for (int i = 0; i < N; i++) {
		res.push_back(vector<int>(N));
		for (int j = 0; j < N; j++) {
			unsigned long long x = 0;
			for (int k = 0; k < N; k++) {
				x += (A[i][k] * B[k][j]);
			}
			res[i][j] = x % 1000;
		}
	}

	return res;
}

void print_mat(const vector<vector<int>>& mat) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
}
