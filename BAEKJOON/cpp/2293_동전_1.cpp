#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> nums, dp;

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	dp.assign(k + 1, 0);

	dp[0] = 1;

	for (int i = 0; i < nums.size(); i++) {
		for (int j = nums[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - nums[i]];
		}
	}

	cout << dp[k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}