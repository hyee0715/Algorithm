#include <iostream>
#include <cstring>

#define MAX 65
using namespace std;

int n;
long long dp[MAX][MAX];

void input() {
	cin >> n;
}

//dp[a][b] = c -> a개의 자릿수를 가지고 있는 수들 중에서 마지막 자릿수가 b일때, 줄어들지 않는 수의 개수는 c개이다.
void solution() {
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = i + 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}

	cout << dp[n][9] << "\n";
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