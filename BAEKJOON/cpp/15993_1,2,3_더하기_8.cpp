#include <iostream>

#define MAX 100000
#define MOD 1000000009
using namespace std;

int n;
long long dp[MAX][3]; // [3]은 1~2만 사용. (1 == 홀수, 2 == 짝수)

//dp[a][b] = c -> 정수 a를 1, 2, 3의 합으로 나타낼 때, 사용한 수의 개수가 홀수(b == 1)이거나, 짝수(b == 2)인 경우의 수는 c개이다.
void solution() {
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 2;
	dp[3][2] = 2;

	for (int i = 4; i <= MAX; i++) {
		// 홀수 개수
		dp[i][1] = (dp[i - 1][2] + dp[i - 2][2] + dp[i - 3][2]) % MOD;
		
		// 짝수 개수
		dp[i][2] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % MOD;
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
		cin >> n;

		cout << dp[n][1] << " " << dp[n][2] << "\n";
	}

	return 0;
}