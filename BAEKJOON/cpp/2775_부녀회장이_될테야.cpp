#include <iostream>
#include <cstring>
#include <vector>

#define MAX 15
using namespace std;

int k, n;
int dp[MAX][MAX];
vector<int> answer;

void solution() {
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < MAX; i++) {
		dp[0][i] = i;
	}

	// Á¡È­½Ä : DP[k][n] = DP[k - 1][1] + DP[k - 1][2] + ... + DP[k - 1][n]
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int m = 0; m <= j; m++) {
				dp[i][j] = dp[i][j] + dp[i - 1][m];
			}
		}
	}

	answer.push_back(dp[k][n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> k >> n;

		solution();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}