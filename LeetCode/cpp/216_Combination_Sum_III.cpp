class Solution {
public:
	vector<int> v;
	bool visit[10];
	vector<vector<int> > answer;

	void dfs(int idx, int cnt, int target, int limit) {
		if (cnt == limit) {
			int sum = 0;

			for (int i = 0; i < v.size(); i++) {
				sum += v[i];
			}

			if (sum == target) {
				answer.push_back(v);
			}
		}
		else {
			for (int i = idx; i <= 9; i++) {
				if (visit[i] == true) continue;
				visit[i] = true;
				v.push_back(i);

				dfs(i, cnt + 1, target, limit);

				visit[i] = false;
				v.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		dfs(1, 0, n, k);

		return answer;
	}
};