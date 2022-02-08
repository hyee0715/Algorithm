#include <iostream>
#include <algorithm>

#define MAX 1010
using namespace std;

int n, m;
int map[MAX][MAX];
int dp[MAX][MAX];

void input() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}

void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = map[i][j];
			}
			else if (i == 1 && j > 1) {
				dp[i][j] = dp[i][j - 1] + map[i][j];
			}
			else if (i > 1 && j == 1) {
				dp[i][j] = dp[i - 1][j] + map[i][j];
			}
			else if (i > 1 && j > 1) {
				dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1])) + map[i][j];
			}
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