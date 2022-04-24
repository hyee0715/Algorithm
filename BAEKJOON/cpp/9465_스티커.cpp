#include <iostream>
#include <algorithm>

#define MAX 100000
using namespace std;

int arr[2][MAX], dp[2][MAX];
int n, answer;

void input() {
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

//dp[a][b] = c -> arr[a][b]번째 스티커까지 왔을 때, 두 변을 공유하지 않는 스티커 점수의 최댓값은 c이다.
void solution() {
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = dp[1][0] + arr[0][1];
	dp[1][1] = dp[0][0] + arr[1][1];

	for (int j = 2; j < n; j++) { // 열을 기준으로 루프를 돌아야 한다. (기존 루프와 반대, 세로로 돌아야 한다.)
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				dp[i][j] = max(max(dp[i + 1][j - 1], dp[i][j - 2]), dp[i + 1][j - 2]) + arr[i][j];
			}
			else { // i == 1
				dp[i][j] = max(max(dp[i - 1][j - 1], dp[i][j - 2]), dp[i - 1][j - 2]) + arr[i][j];
			}
		}
	}

	answer = max(dp[0][n - 1], dp[1][n - 1]);

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