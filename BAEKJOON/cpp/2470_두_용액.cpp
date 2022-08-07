#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long ans1, ans2;
vector<long long> nums;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		nums.push_back(a);
	}
}

void solution() {
	sort(nums.begin(), nums.end());

	int left = 0;
	int right = nums.size() - 1;
	int result = 0x7fffffff;

	while (left < right) {
		int sum = nums[left] + nums[right];

		if (abs(sum) < result) {
			result = abs(sum);
			ans1 = nums[left];
			ans2 = nums[right];
		
			if (sum == 0)
				break;
		}

		if (sum < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << ans1 << " " << ans2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}