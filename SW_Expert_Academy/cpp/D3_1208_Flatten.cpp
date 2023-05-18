#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dumpCnt;
vector<int> nums;

void initialize() {
	nums.clear();
}

void input() {
	cin >> dumpCnt;

	for (int i = 0; i < 100; i++) {
		int n;
		cin >> n;

		nums.push_back(n);
	}
}

void solution() {
	for (int i = 0; i < dumpCnt; i++) {
		sort(nums.begin(), nums.end());

		nums[0]++;
		nums[nums.size() - 1]--;
	}

	sort(nums.begin(), nums.end());
	int answer = nums[nums.size() - 1] - nums[0];

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