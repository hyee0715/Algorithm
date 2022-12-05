#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
vector<int> nums;

void input() {
	cin >> n >> k;
}

void solution() {
	for (int i = 1; i <= k; i++) {
		string s = to_string(n * i);
		reverse(s.begin(), s.end());
		nums.push_back(stoi(s));
	}

	sort(nums.begin(), nums.end());
	
	cout << nums[nums.size() - 1];
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