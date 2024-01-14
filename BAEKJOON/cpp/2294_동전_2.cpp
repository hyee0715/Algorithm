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
	dp.assign(k + 1, 100001);

	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (i < nums[j]) {
				continue;
			}

			dp[i] = min(dp[i], dp[i - nums[j]] + 1);
		}
	}

	for (int i = 0; i <= k; i++) {
		if (dp[i] == 100001) {
			dp[i] = -1;
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