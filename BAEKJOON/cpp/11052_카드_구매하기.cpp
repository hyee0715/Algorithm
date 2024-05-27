#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr, dp;

void input() {
	cin >> n;
	
	arr.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	dp.assign(n + 1, 0);

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i], arr[i]);
		
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
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