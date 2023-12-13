class Solution {
public:
	void initParent(vector<int>& parent) {
		for (int i = 0; i < parent.size(); i++) {
			parent[i] = i;
		}
	}

	int findParent(int x, vector<int>& parent) {
		if (parent[x] == x) {
			return x;
		}

		return findParent(parent[x], parent);
	}

	bool isSameParent(int x, int y, vector<int>& parent) {
		x = findParent(x, parent);
		y = findParent(y, parent);

		if (x == y) {
			return true;
		}

		return false;
	}

	void unionParent(int x, int y, vector<int>& parent) {
		x = findParent(x, parent);
		y = findParent(y, parent);

		if (x < y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}

	int countComponents(int n, vector<vector<int>>& edges) {
		vector<int> parent(n);
		set<int> count;
		int answer = 0;

		initParent(parent);

		for (vector<int> e : edges) {
			int a = e[0];
			int b = e[1];

			unionParent(a, b, parent);
		}

		for (int i = 0; i < n; i++) {
			parent[i] = findParent(i, parent);
		}

		for (int i = 0; i < n; i++) {
			count.insert(parent[i]);
		}

		answer = count.size();
		return answer;
	}
};