#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nums;

void input() {
	int n;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		nums.push_back(n);
	}
}

void solution() {
	sort(nums.begin(), nums.end());

	int sum = 0;
	for (int num : nums) {
		sum += num;
	}

	int avg = sum / 5;
	int mid = nums[2];

	cout << avg << "\n" << mid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}