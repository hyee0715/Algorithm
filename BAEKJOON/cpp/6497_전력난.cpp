#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001
using namespace std;

int m, n, sum, total = 0;
vector<pair<int, pair<int, int>>> path;
int parent[MAX];

void initialize() {
	sum = 0;
	total = 0;
	path.clear();

	for (int i = 1; i <= m; i++) {
		parent[i] = i;
	}
}

void input() {
	int x, y, z;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		path.push_back({ z, {x, y} });
		total += z;
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
	else
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

void solution() {
	sort(path.begin(), path.end());

	for (int i = 0; i < n; i++) {
		if (same_parent(path[i].second.first, path[i].second.second) == false) {
			union_parent(path[i].second.first, path[i].second.second);
			sum = sum + path[i].first;
		}
	}

	cout << total - sum << "\n"; // 절약할 수 있는 최대 비용이므로 모두 더한 값에서 최소경로 값을 뺀다.
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> m >> n;

		if (m == 0 && n == 0)
			break;

		initialize();
		input();
		solution();
	}

	return 0;
}