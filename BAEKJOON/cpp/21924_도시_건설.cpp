#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long all_path_sum = 0, minimum_cost = 0;
vector<pair<int, pair<int, int>>> paths;
vector<int> parent;

void input() {
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		paths.push_back({ c, {a, b} });

		all_path_sum += c;
	}
}

void parent_initialize() {
	parent.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

bool same_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x == y)
		return true;
	return false;
}

bool are_paths_all_connected() {
	for (int i = 1; i < n; i++) {
		if (same_parent(i, i + 1) == false)
			return false;
	}

	return true;
}

void solution() {
	parent_initialize();

	sort(paths.begin(), paths.end());

	for (int i = 0; i < paths.size(); i++) {
		if (same_parent(paths[i].second.first, paths[i].second.second) == false) {
			union_parent(paths[i].second.first, paths[i].second.second);

			minimum_cost += paths[i].first;
		}
	}

	if (!are_paths_all_connected()) {
		cout << -1;
		return;
	}

	cout << all_path_sum - minimum_cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}