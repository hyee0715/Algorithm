#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp(100001, 0);

void input() {
	cin >> n;
}

void solution() {
	dp[1] = 3;
	dp[2] = 7;

	if (n <= 2) {
		cout << dp[n];
	
		return;
	}

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + 2 * dp[i - 1]) % 9901;
	}

	cout << dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}