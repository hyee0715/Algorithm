#include <iostream>

#define MAX 101
using namespace std;

int n;
long long dp[MAX];

void input() {
	cin >> n;
}

void solution() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;

	for (int i = 8; i <= n; i++) {
		dp[i] = dp[i - 5] + dp[n - 1];
	}

	cout << dp[n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}