#include <iostream>

#define MAX 10001
using namespace std;

int n, m;
long long dp[MAX][101];

void input() {
	cin >> n >> m;
}

//dp[n][m] = c -> n초의 시간동안 싸우는데 A 스킬 시간이 1초이고 B 스킬 시간이 m초일 때, 
//가능한 스킬 조합은 C개이다.
void solution() {
	//dp[1][2~100]을 모두 1로 초기화
	for (int i = 2; i <= 100; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (i > j) {
				dp[i][j] = (dp[i - 1][j] + dp[i - j][j]) % 1000000007;
			}
			else if (i == j) {
				dp[i][j] = 2;
			}
			else { // i < j
				dp[i][j] = 1;
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