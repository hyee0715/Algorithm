#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n;
string a;
vector<string> nums;
set<string> st;

bool compare(string a, string b) {
	if (a.size() < b.size()) {
		return true;
	}
	return false;
}

void initialize() {
	nums.clear();
	st.clear();
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	sort(nums.begin(), nums.end(), compare);

	for (int i = 0; i < nums.size(); i++) {
		string s;

		for (int j = 0; j < nums[i].size(); j++) {
			s += nums[i][j];

			if (st.find(s) != st.end()) {
				cout << "NO\n";
				return;
			}
		}

		st.insert(s);
	}

	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}

	return 0;
}