#include <iostream>
#include <vector>
using namespace std;

int n, m, answer = 0;
vector<int> nums, cum;

void input() {
	cin >> n >> m;

	nums.push_back(0);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	//make cumulative sum array
	cum.push_back(0);

	for (int i = 1; i < nums.size(); i++) {
		cum.push_back(cum[i - 1] + nums[i]);
	}

	//calculate
	int left = 0;
	int right = 1;

	while (left <= right && right < cum.size()) {
		if (cum[right] - cum[left] > m) {
			left++;
		}
		else if (cum[right] - cum[left] == m) {
			answer++;
			left++;
		}
		else
			right++;
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