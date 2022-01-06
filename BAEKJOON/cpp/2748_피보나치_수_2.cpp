#include <iostream>
#include <algorithm>

#define endl "\n"
#define MAX 90
using namespace std;

long long dp[MAX];
int n;
long long  result = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	fill(dp, dp + MAX, 0);

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	result = dp[n];

	cout << result;

	return 0;
}