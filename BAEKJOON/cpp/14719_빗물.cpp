#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
vector<int> nums, lefts, rights;

void input() {
	cin >> h >> w;

	int a;
	for (int i = 0; i < w; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	lefts.assign(nums.size(), 0);
	rights.assign(nums.size(), 0);

	int cur = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (cur <= nums[i]) {
			cur = nums[i];

			lefts[i] = 0;
		}
		else {
			lefts[i] = cur - nums[i];
		}
	}

	cur = 0;
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (cur <= nums[i]) {
			cur = nums[i];

			rights[i] = 0;
		}
		else {
			rights[i] = cur - nums[i];
		}
	}

	vector<int> waters(nums.size(), 0);

	int answer = 0;

	for (int i = 0; i < waters.size(); i++) {
		waters[i] = min(lefts[i], rights[i]);
		answer += waters[i];
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