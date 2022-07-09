#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> nums, v;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	for (int i = 0; i < nums.size(); i++) {
		if (v.size() == 0 || v[v.size() - 1] < nums[i])
			v.push_back(nums[i]);
		else {
			int pos = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
			v[pos] = nums[i];
		}
	}

	cout << v.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}