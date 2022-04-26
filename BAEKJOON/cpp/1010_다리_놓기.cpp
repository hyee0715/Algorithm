#include <iostream>
#include <cstring>

#define MAX 31
using namespace std;

int n, m;
int dp[MAX][MAX];

void input() {
	cin >> n >> m;
}

//dp[a][b] = c -> 서쪽의 사이트가 a개, 동쪽의 사이트가 b개 있을 때, 다리를 지을 수 있는 경우의 수는 c개이다.
void solution() {
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= m; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			for (int k = j - 1; k >= i; k--) {
				dp[i][j] += dp[i - 1][k];
			}

			dp[i][j] += 1;
		}
	}

	cout << dp[n][m] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}