#include <iostream>
#include <vector>
using namespace std;

vector<int> nums, v, answer;
vector<bool> visit;

void input() {
	int a;

	for (int i = 0; i < 9; i++) {
		cin >> a;
		nums.push_back(a);
	}
}

int getSum() {
	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	return sum;
}

void copy() {
	answer.assign(v.size(), 0);

	for (int i = 0; i < v.size(); i++) {
		answer[i] = v[i];
	}
}

void dfs(int idx, int cnt) {
	if (cnt == 7) {
		int sum = getSum();

		if (sum == 100) {
			copy();
		}

		return;
	}

	for (int i = idx; i < 9; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(nums[i]);
		dfs(i, cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

void solution() {
	visit.assign(9, false);

	dfs(0, 0);

	for (int i = 0; i < answer.size(); i++) {
		if (i == answer.size() - 1) {
			cout << answer[i];
		}
		else {
			cout << answer[i] << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}