#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> importance, time;

void input() {
	cin >> n >> k;
	
	importance.assign(k + 1, 0);
	time.assign(k + 1, 0);

	for (int i = 1; i <= k; i++) {
		cin >> importance[i] >> time[i];
	}
}

void solution() {
	vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (time[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + importance[i]);
			}
		}
	}

	cout << dp[k][n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}