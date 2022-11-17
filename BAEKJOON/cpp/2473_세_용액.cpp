#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define INF 3000000001
using namespace std;

int n;
long long min_sum = INF;
vector<int> nums, answer;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

void find_third_element(int first, int second) {
	int left = second + 1;
	int right = nums.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		long long sum = 0;
		sum += nums[first];
		sum += nums[second];
		sum += nums[mid];

		if (abs(sum) < abs(min_sum)) {
			min_sum = sum;

			answer.clear();

			answer.push_back(nums[first]);
			answer.push_back(nums[second]);
			answer.push_back(nums[mid]);
		}

		if (sum == 0) {
			return;
		}

		if (sum < 0) {
			left = mid + 1;
			continue;
		}

		if (sum > 0) {
			right = mid - 1;
		}
	}
}

void find_second_element(int first) {
	for (int j = first + 1; j < nums.size() - 1; j++) {
		find_third_element(first, j);
	}
}

void solution() {
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 2; i++) {
		find_second_element(i);
	}

	sort(answer.begin(), answer.end());

	for (int n : answer) {
		cout << n << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}