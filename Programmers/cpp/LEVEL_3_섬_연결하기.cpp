#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
vector<int> parent;

int find_parent(int x) {
	if (parent[x] == x) {
		return x;
	}

	return parent[x] = find_parent(parent[x]);
}

bool same_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x == y) {
		return true;
	}

	return false;
}

void union_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		parent.push_back(i);
	}

	for (int i = 0; i < costs.size(); i++) {
		int x = costs[i][0];
		int y = costs[i][1];
		int cost = costs[i][2];

		edges.push_back({ cost, {x, y} });
		edges.push_back({ cost, {y, x} });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		if (!same_parent(edges[i].second.first, edges[i].second.second)) {
			union_parent(edges[i].second.first, edges[i].second.second);
			answer += edges[i].first;
		}
	}

	return answer;
}