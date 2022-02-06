#include <iostream>
#include <algorithm>

#define MAX 35
using namespace std;

int n, k;
int arr[MAX][MAX];
int dp[MAX][MAX];

void input() {
	cin >> n >> k;
}

void solution() {
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j == 1 || j == n) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
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