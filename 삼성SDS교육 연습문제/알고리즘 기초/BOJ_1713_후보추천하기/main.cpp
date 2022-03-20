/* BOJ_1713 후보 추천하기 */
/* hanabzu */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, total, n, n_pic = 0, min_vote, latest, n_last;
int vote[101];
int last[101];
int pic[21];
vector<int> candi;
bool find_n(int n);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> total;
	for (int i = 1; i <= total; i++) {
		cin >> n;
		
		if (find_n(n)) {
			vote[n]++;
		}
		else if (n_pic < N) {
			pic[++n_pic] = n;
			vote[n]++;
			last[n] = i;
		}
		else {
			candi.clear();
			min_vote = 1001;
			latest = 1001;
			n_last = 0;
			for (int j = 1; j <= 100; j++) {
				if (vote[j] > 0 && vote[j] < min_vote ) {
					candi.clear();
					candi.push_back(j);
					min_vote = vote[j];
				}
				else if (vote[j] == min_vote) {
					candi.push_back(j);
				}
			}

			for (vector<int>::iterator it = candi.begin(); it != candi.end(); it++) {
				if (last[*it] < latest) {
					n_last = *it;
					latest = last[*it];
				}
			}

			for (int j = 1; j <= n_pic; j++) {
				if (pic[j] == n_last) {
					pic[j] = n;
					last[n] = i;
					vote[n]++;
					vote[n_last] = 0;
				}
			}
		}
	}


	sort(pic + 1, pic + n_pic+1);

	for (int i = 1; i <= n_pic; i++) {
		cout << pic[i] << ' ';
	}

	return 0;
}

bool find_n(int n) {
	for (int i = 1; i <= N; i++) {
		if (pic[i] == n) {
			return true;
		}
	}
	return false;
}
