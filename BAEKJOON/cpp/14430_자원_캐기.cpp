#include <iostream>
#include <algorithm>

#define MAX 301
using namespace std;

int n, m;
int arr[MAX][MAX], dp[MAX][MAX];

void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
}

void solution() {
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}

	for (int j = 2; j <= m; j++) {
		dp[1][j] = dp[1][j - 1] + arr[1][j];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
		}
	}

	cout << dp[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}