#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k;
vector<char> op;
vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
vector<string> results;

void input() {
	cin >> k;

	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;

		op.push_back(c);
	}
}

bool check(vector<int>& v) {
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '<') {
			if (v[i] > v[i + 1]) {
				return false;
			}
		}
		else {
			if (v[i] < v[i + 1]) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int cnt, vector<int>& v, vector<bool>& visit) {
	if (cnt == k + 1) {
		if (check(v)) {
			string s = "";

			for (int i = 0; i < v.size(); i++) {
				s += (char)(v[i] + '0');
			}

			results.push_back(s);
		}
	}
	else {
		for (int i = 0; i < nums.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(nums[i]);
			dfs(cnt + 1, v, visit);
			v.pop_back();
			visit[i] = false;
		}
	}
}

void solution() {
	vector<bool> visit(nums.size(), false);
	vector<int> v;

	dfs(0, v, visit);

	sort(results.begin(), results.end());
	cout << results[results.size() - 1] << "\n" << results[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}