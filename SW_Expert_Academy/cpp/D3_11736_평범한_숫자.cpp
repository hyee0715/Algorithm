#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int max_num, min_num;
vector<int> v;
int answer = 0;

void initialize() {
	max_num = 0;
	min_num = 0;
	v.clear();
	answer = 0;
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		v.push_back(a);
	}
}

void solution() {
	for (int i = 1; i < v.size() - 1; i++) {
		vector<int> nums;

		nums.push_back(v[i - 1]);
		nums.push_back(v[i]);
		nums.push_back(v[i + 1]);

		sort(nums.begin(), nums.end());

		if (v[i] == nums[1]) {
			answer++;
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		initialize();
		input();

		cout << "#" << i << " ";
		solution();
		cout << "\n";
	}

	return 0;
}