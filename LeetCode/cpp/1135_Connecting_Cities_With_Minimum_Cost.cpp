class Solution {
public:
	vector<pair<int, pair<int, int>>> cities;
	vector<int> parent;

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

	int minimumCost(int n, vector<vector<int>>& connections) {
		int cost = 0;

		for (vector<int> connection : connections) {
			cities.push_back({ connection[2], {connection[0], connection[1]} });
		}

		parent.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		sort(cities.begin(), cities.end());

		for (int i = 0; i < cities.size(); i++) {
			if (!sameParent(cities[i].second.first, cities[i].second.second)) {
				unionParent(cities[i].second.first, cities[i].second.second);
				cost += cities[i].first;
			}
		}

		for (int i = 1; i < parent.size(); i++) {
			parent[i] = findParent(parent[i]);
		}

		for (int i = 1; i < parent.size() - 1; i++) {
			if (parent[i] != parent[i + 1]) {
				cost = -1;
				break;
			}
		}

		return cost;
	}
};