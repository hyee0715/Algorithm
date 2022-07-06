#include <iostream>
#include <algorithm>

#define MAX 500
using namespace std;

int n, answer = 0;
int arr[MAX][MAX], dp[MAX][MAX];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
}

void solution() {
	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
		answer = max(answer, dp[n - 1][i]);
	
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