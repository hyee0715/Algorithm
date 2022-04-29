#include <iostream>

#define MAX 1001
using namespace std;

int n, answer = 0;
int dp[MAX][10];

void input() {
	cin >> n;
}

//dp[a][b] = c -> 길이가 a이고, 마지막 자릿수가 b일 때 오르막 수 개수는 c개이다.
void solution() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;

		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	for (int i = 0; i <= 9; i++) {
		answer += dp[n][i];
	}

	cout << answer % 10007;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}