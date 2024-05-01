#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> nums, cur, ans;
vector<vector<int>> orders;

void input() {
	cin >> n >> m;

	nums.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		orders.push_back({ a - 1, b - 1, c });
	}
}

void solution() {
	cur.assign(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int start = orders[i][0];
		int end = orders[i][1];
		int num = orders[i][2];

		cur[start] += num;
		cur[end + 1] += (num * -1);
	}

	for (int i = 1; i < cur.size(); i++) {
		cur[i] = cur[i - 1] + cur[i];
	}
	
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] + cur[i] << " ";
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