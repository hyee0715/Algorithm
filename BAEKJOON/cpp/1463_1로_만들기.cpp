#include <iostream>
#include <algorithm>

#define MAX 1000001
using namespace std;

int n;
int dp[MAX];

void input() {
	cin >> n;
}

void solution() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0)
			dp[i] = min(min(dp[i - 1] + 1, dp[i / 2] + 1), dp[i / 3] + 1);
		else if (i % 2 == 0 && i % 3 != 0)
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		else if (i % 2 != 0 && i % 3 == 0)
			dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		else
			dp[i] = dp[i - 1] + 1;
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