#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001
using namespace std;

int n;
int dp[MAX][10]; 
vector<int> answer;

// dp[a][b] = c -> 비밀번호의 길이가 a이고, 비밀번호의 마지막 숫자가 b일때, 가능한 비밀번호의 개수는 c이다.
void solution() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = (dp[i - 1][7]) % 1234567;
			}
			else if (j == 1) {
				dp[i][j] = (dp[i - 1][2] + dp[i - 1][4]) % 1234567;
			}
			else if (j == 2) {
				dp[i][j] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % 1234567;
			}
			else if (j == 3) {
				dp[i][j] = (dp[i - 1][2] + dp[i - 1][6]) % 1234567;
			}
			else if (j == 4) {
				dp[i][j] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % 1234567;
			}
			else if (j == 5) {
				dp[i][j] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % 1234567;
			}
			else if (j == 6) {
				dp[i][j] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % 1234567;
			}
			else if (j == 7) {
				dp[i][j] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % 1234567;
			}
			else if (j == 8) {
				dp[i][j] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % 1234567;
			}
			else if (j == 9) {
				dp[i][j] = (dp[i - 1][6] + dp[i - 1][8]) % 1234567;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	solution();

	while (tc--) {
		int sum = 0;
		cin >> n;

		for (int i = 0; i <= 9; i++) {
			sum += dp[n][i];
		}

		answer.push_back(sum % 1234567);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}