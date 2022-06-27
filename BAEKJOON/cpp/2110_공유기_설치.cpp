#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
long long answer = 0;
vector<int> nums;

void input() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
}

int check(int target) {
	int prev = nums[0];
	int cnt = 1;

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] - prev >= target) {
			cnt++;
			prev = nums[i];
		}
	}

	return cnt;
}

void solution() {
	sort(nums.begin(), nums.end());

	int left = 0;
	int right = nums[nums.size() - 1];

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (check(mid) >= c) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}