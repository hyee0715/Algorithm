#include <iostream>
#include <algorithm>

#define MAX 1001
using namespace std;

int n;
int arr[MAX][3];
int dp[MAX][3];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			cin >> arr[i][j];
		}
	}
}

void solution() {
	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			if (j == 0)
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][j];
			else if (j == 1) {
				dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][j];
			}
			else if (j == 2) {
				dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][j];
			}
		}
	}

	int answer = min(min(dp[n][0], dp[n][1]), dp[n][2]);
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}