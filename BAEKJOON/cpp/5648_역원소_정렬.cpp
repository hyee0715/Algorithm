#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> nums;
vector<long long> answer;

void input() {
	cin >> n;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		nums.push_back(s);
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		reverse(nums[i].begin(), nums[i].end());
		long long ll = stol(nums[i]);
		answer.push_back(ll);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
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