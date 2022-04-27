#include <iostream>
#include <cstring>

#define MAX 100001
using namespace std;

int n;
long long dp[MAX][4]; // [4]는 1~3번 인덱스만 사용
long long answer;

void input() {
	cin >> n;
}

//dp[a][b] = c -> 정수 a를 1,2,3의 합으로 나타낼 때, 마지막으로 더하는 수가 b일 때 경우의 수는 c이다.
void solution() {
	memset(dp, 0, sizeof(dp));

	dp[1][1] = 1;
	dp[2][2] = 1;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}

	answer = (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009;
	cout << answer << "\n";
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