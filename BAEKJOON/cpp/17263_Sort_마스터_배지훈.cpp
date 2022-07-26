#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> nums;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	sort(nums.begin(), nums.end());

	cout << nums[nums.size() - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}