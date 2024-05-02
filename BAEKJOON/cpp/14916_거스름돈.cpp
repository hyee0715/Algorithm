#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	vector<int> dp(100000 + 1, 0);

	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;

	if (n <= 5) {
		cout << dp[n];
		return;
	}

	for (int i = 6; i <= n; i++) {
		int n1 = dp[i - 2];
		int n2 = dp[i - 5];

		if (n1 == -1) {
			dp[i] = n2 + 1;
		}
		else if (n2 == -1) {
			dp[i] = n1 + 1;
		}
		else {
			dp[i] = min(n1, n2) + 1;
		}
	}

	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}