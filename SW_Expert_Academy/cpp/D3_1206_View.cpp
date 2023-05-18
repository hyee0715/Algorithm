#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> nums;

void initialize() {
	nums.clear();
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		nums.push_back(a);
	}
}

void solution() {
	int answer = 0;

	for (int i = 2; i < nums.size() - 2; i++) {
		if (nums[i - 2] < nums[i] && nums[i - 1] < nums[i] && nums[i] > nums[i + 1] && nums[i] > nums[i + 2]) {
			int maxNeighbor = max(max(nums[i - 2], nums[i - 1]), max(nums[i + 1], nums[i + 2]));
			answer += (nums[i] - maxNeighbor);
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		initialize();
		input();

		cout << "#" << i << " ";
		solution();
		cout << "\n";
	}

	return 0;
}