/* BOJ_3955 캔디 분배 */
/* hanabzu */

#include <iostream>
#include <algorithm>
#include <numeric>
#define MAXN 1000000000

using namespace std;

int t, K, C, x, y, d;

void solution();
int gcdExtended(int a, int b, int& x, int& y);
void modInverse(int a, int m);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> K >> C;
		solution();
	}

	return 0;
}

void solution() { // C*y = K*x+1 -> C*y ≡ 1(mod K)
	if (gcd(K, C) != 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
    modInverse(K, C);

	return;
}

// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int& x, int& y)
{
    // Base Case 
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b % a, a, x1, y1);

    // Update x and y using results of recursive 
    // call 
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

// Function to find modulo inverse of a 
void modInverse(int a, int m)
{
    int x, y;
    int gcd = gcdExtended(a, m, x, y); // 
    if (gcd != 1)
        cout << "IMPOSSIBLE\n";
    else
    {
        // m is added to handle negative x 
        int res = (x % m + m) % m;
        long long ans = y;
        while (C * ans <= K) ans += K;
        if (ans > MAXN) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}