#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, r, x, answer = 0;
vector<int> nums, v;
vector<bool> visit;

void input() {
	cin >> n >> l >> r >> x;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

void dfs(int idx, int cnt, int target) { //combination
	if (cnt == target) {
		vector<int> temp(v.size());

		for (int i = 0; i < v.size(); i++) {
			temp[i] = v[i];
		}

		sort(temp.begin(), temp.end());

		if (temp[temp.size() - 1] - temp[0] < x) {
			return;
		}

		int sum = 0;

		for (int i = 0; i < temp.size(); i++) {
			sum += temp[i];
		}

		if (sum >= l && sum <= r) {
			answer++;
		}

		return;
	}
	else {
		for (int i = idx; i < n; i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			v.push_back(nums[i]);
			dfs(i, cnt + 1, target);
			visit[i] = false;
			v.pop_back();
		}
	}
}

void solution() {
	visit.assign(n, false);

	for (int i = 2; i <= n; i++) {
		dfs(0, 0, i);
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