#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> weight, value;

void input() {
	cin >> n >> k;

	weight.assign(n + 1, 0);
	value.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
}

void solution() {
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (weight[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}
	}

	cout << dp[n][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}