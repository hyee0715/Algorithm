#include <iostream>
#include <algorithm>

#define MAX 100001
using namespace std;

int n;
int dp[MAX];

void input() {
	cin >> n;
}

void solution() {
	dp[1] = 1;
	dp[2] = 1;
	dp[5] = 1;
	dp[7] = 1;

	dp[3] = min(dp[1], dp[2]) + 1;
	dp[4] = min(dp[2], dp[3]) + 1;
	dp[6] = min(min(dp[1], dp[4]), dp[5])+ 1;

	for (int i = 8; i <= n; i++) {
		dp[i] = min(min(dp[i - 1], dp[i - 2]), min(dp[i - 5], dp[i - 7])) + 1;
	}

	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}