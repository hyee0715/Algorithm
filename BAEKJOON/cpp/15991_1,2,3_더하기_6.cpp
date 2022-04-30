#include <iostream>
#include <cstring>

#define MAX 100001
#define MOD 1000000009
using namespace std;

int n;
long long answer = 0;
long long dp[MAX][4]; //[4]는 1~3만 사용한다.

void input() {
	cin >> n;
}

//dp[a][b] = c -> 정수 a를 1, 2, 3으로 나타낼 때, 가장 첫번째와 마지막으로 더하는 수가 b일 때의 경우의 수는 c개이다.
void solution() {
	memset(dp, 0, sizeof(dp));
	
	dp[1][1] = 1; //1
	
	dp[2][1] = 1; //1+1
	dp[2][2] = 1; //2
	
	dp[3][1] = 1; //1+1+1
	dp[3][3] = 1; //3
	
	dp[4][1] = 2; //1+1+1+1, 1+2+1
	dp[4][2] = 1; //2+0+2

	dp[5][1] = 2; //1+1+1+1, 1+3+1
	dp[5][2] = 1; //2+1+2

	dp[6][1] = 3; //1+1+1+1+1, 1+1+2+1+1, 1+2+0+2+1
	dp[6][2] = 2; //2+1+1+2, 2+2+2
	dp[6][3] = 1; //3+0+3

	for (int i = 7; i <= n; i++) {
		dp[i][1] = (dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) % MOD;
		dp[i][2] = (dp[i - 4][1] + dp[i - 4][2] + dp[i - 4][3]) % MOD;
		dp[i][3] = (dp[i - 6][1] + dp[i - 6][2] + dp[i - 6][3]) % MOD;
	}

	answer = dp[n][1] + dp[n][2] + dp[n][3];

	cout << answer % MOD << "\n";
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