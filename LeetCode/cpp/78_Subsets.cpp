class Solution {
public:
	bool visit[10];
	vector<int> v;
	vector<vector<int>> answer;

	void dfs(int idx, int cnt, int limit, vector<int>& nums) {
		if (cnt == limit) {
			answer.push_back(v);
		}
		else {
			for (int i = idx; i < nums.size(); i++) {
				if (visit[i] == true) continue;
				visit[i] = true;
				v.push_back(nums[i]);
				dfs(i, cnt + 1, limit, nums);
				visit[i] = false;
				v.pop_back();
			}
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		answer.push_back(v);

		for (int i = 1; i <= nums.size(); i++) {
			memset(visit, false, sizeof(visit));
			dfs(0, 0, i, nums);
		}

		return answer;
	}
};