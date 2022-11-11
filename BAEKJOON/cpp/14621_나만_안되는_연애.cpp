#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, path_sum = 0;
vector<char> gender;
vector<pair<int, pair<int, int>>> path;
vector<int> parent;

void input() {
	cin >> n >> m;

	gender.push_back('N');

	char ch;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		gender.push_back(ch);
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		path.push_back({ c, {a, b} });
	}
}

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}

bool same_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x == y) 
		return true;

	return false;
}

void union_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

bool all_connected() {
	for (int i = 1; i < parent.size() - 1; i++) {
		if (!same_parent(parent[i], parent[i + 1]))
			return false;
	}

	return true;
}

void solution() {
	parent.assign(n + 1, -1);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	sort(path.begin(), path.end());

	for (int i = 0; i < path.size(); i++) {
		int x = path[i].second.first;
		int y = path[i].second.second;
		if (!same_parent(x, y) && (gender[x] != gender[y])) {
			union_parent(x, y);

			path_sum += path[i].first;
		}
	}

	if (all_connected()) {
		cout << path_sum;
		return;
	}

	cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}