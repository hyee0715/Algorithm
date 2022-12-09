#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;

void solution() {
	for (int i = 1; i <= 20; i++) {
		nums.push_back(i);
	}

	int start, end;
	for (int i = 0; i < 10; i++) {
		cin >> start >> end;

		reverse(nums.begin() + start - 1, nums.begin() + end);
	}

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}