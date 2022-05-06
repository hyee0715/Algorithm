#include <iostream>
#include <cstring>

#define MAX 1001
#define MOD 1000000009
using namespace std;

int n, m;
long long dp[MAX][MAX];

//dp[a][b] = c -> 정수 a를 1, 2, 3의 합으로 나타낼 때, 사용한 수의 개수가 b개인 경우의 수는 c개이다.
void solution() {
	memset(dp, 0, sizeof(dp));

	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
	
	for (int i = 4; i < MAX; i++) {
		for (int j = 2; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % MOD;
		}
	}
}

void find_answer() {
	long long answer = 0;
	for (int i = 1; i <= m; i++) {
		answer += dp[n][i];
		answer = (answer) % MOD;
	}

	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> n >> m;;

		find_answer();
	}

	return 0;
}