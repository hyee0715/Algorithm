#include <iostream>
#include <cstring>

#define MAX 1001
#define MOD 1000000009
using namespace std;

int n, m;
long long dp[MAX][MAX];

void input() {
	cin >> n >> m;
}

//dp[a][b] = c -> 정수 a를 1, 2, 3으로 나타낼 때, 가장 첫번째와 마지막으로 더하는 수가 b일 때의 경우의 수는 c개이다.
void solution() {
	memset(dp, 0, sizeof(dp));
	
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;

	for (int i = 4; i < MAX; i++) { // 4~1000
		for (int j = 2; j < MAX; j++) { //dp[i][j]의 j가 1인 경우는 i == 4부터는 의미가 없으므로 j는 2부터 시작한다. (1개의 숫자로만 나타내는 것은 1, 2, 3이 전부이다.)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();

		cout << dp[n][m] << "\n";
	}

	return 0;
}