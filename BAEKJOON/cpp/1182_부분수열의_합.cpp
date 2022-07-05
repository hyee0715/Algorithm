#include <iostream>
#include <vector>
using namespace std;

int n, s, answer = 0;
vector<int> v, nums;
vector<bool> visit(20, false);

void input() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
}

void dfs(int idx, int cnt, int limit) {
	if (cnt == limit) {
		int sum = 0;

		for (int i = 0; i < v.size(); i++)
			sum += v[i];

		if (sum == s)
			answer++;

		return;
	}
	else {
		for (int i = idx; i < nums.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(nums[i]);
			dfs(i, cnt + 1, limit);
			v.pop_back();
			visit[i] = false;
		}
	}
}

void solution() {
	for (int i = 1; i <= nums.size(); i++)
		dfs(0, 0, i);

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