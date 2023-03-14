#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> parent;
vector<pair<int, int>> friends;
unordered_map<int, vector<int>> enemy;
int answer = 0;

void input() {
	cin >> n >> m;

	char c;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> c >> a >> b;

		if (c == 'F') {
			friends.push_back({ a, b });
			friends.push_back({ b, a });
			continue;
		}

		enemy[a].push_back(b);
		enemy[b].push_back(a);
	}
}

int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	
	return parent[x] = findParent(parent[x]);
}

bool sameParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x == y) {
		return true;
	}

	return false;
}

void unionParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

void solution() {
	parent.assign(n + 1, 0);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < friends.size(); i++) {
		if (!sameParent(friends[i].first, friends[i].second)) {
			unionParent(friends[i].first, friends[i].second);
		}
	}

	for (auto m : enemy) {
		vector<int> v = m.second;

		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (!sameParent(v[i], v[j])) {
					unionParent(v[i], v[j]);
				}
			}
		}
	}

	unordered_map<int, int> relationCount;

	for (int i = 1; i < parent.size(); i++) {
		parent[i] = findParent(parent[i]);

		relationCount[parent[i]]++;
	}

	answer = relationCount.size();

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