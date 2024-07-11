class Solution {
public:
	vector<int> parent;

	void initParent(int n) {
		parent.assign(n, 0);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int findParent(int n) {
		if (parent[n] == n) {
			return n;
		}

		return findParent(parent[n]);
	}

	bool sameParent(int a, int b) {
		a = findParent(a);
		b = findParent(b);

		if (a == b) {
			return true;
		}

		return false;
	}

	void unionParent(int a, int b) {
		a = findParent(a);
		b = findParent(b);

		if (a < b) {
			parent[b] = a;
		}
		else {
			parent[a] = b;
		}
	}

	bool allSameParent(int n) {
		for (int i = 0; i < n - 1; i++) {
			if (!sameParent(i, i + 1)) {
				return false;
			}
		}

		return true;
	}

	int earliestAcq(vector<vector<int>>& logs, int n) {
		int answer = -1;

		sort(logs.begin(), logs.end());

		initParent(n);

		for (vector<int> log : logs) {
			int moment = log[0];
			int a = log[1];
			int b = log[2];

			if (!sameParent(a, b)) {
				unionParent(a, b);
			}

			if (allSameParent(n)) {
				answer = moment;

				break;
			}
		}

		return answer;
	}
};