#include <iostream>
#include <cstring>

#define MAX 10001
using namespace std;

int n, answer;
int dp[MAX][4]; //[4]는 1~3만 사용

void input() {
	cin >> n;
}

//dp[a][b] = c -> 정수 a를 1, 2, 3의 합으로 나타낼 때, 마지막으로 더하는 수가 b인 경우의 수는 c개이다.
void solution() {
	memset(dp, 0, sizeof(dp));

	dp[1][1] = 1; //1
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp[2][1] = 1; //1 + 1
	dp[2][2] = 1; //2
	dp[2][3] = 0;
	dp[3][1] = 1; //1 + 1 + 1
	dp[3][2] = 1; //1 + 2
	dp[3][3] = 1; //3

	for (int i = 4; i <= n; i++) {
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	answer = dp[n][1] + dp[n][2] + dp[n][3];
	
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