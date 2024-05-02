#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> nums, dp;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	int answer = 1;

	dp.assign(nums.size(), 0);
	dp[0] = 1;

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i - 1] <= nums[i]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = 1;
		}

		answer = max(answer, dp[i]);
	}

	dp.assign(nums.size(), 0);
	dp[0] = 1;

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i - 1] >= nums[i]) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = 1;
		}

		answer = max(answer, dp[i]);
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}