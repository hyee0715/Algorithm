class Solution {
public:
	void dfs(int cnt, vector<int>& v, vector<bool>& visit, vector<int>& nums, vector<vector<int>>& answer) {
		if (cnt == nums.size()) {
			answer.push_back(v);
			return;
		}
		else {
			for (int i = 0; i < nums.size(); i++) {
				if (visit[i] == true) continue;
				visit[i] = true;
				v.push_back(nums[i]);
				dfs(cnt + 1, v, visit, nums, answer);
				v.pop_back();
				visit[i] = false;
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> answer;
		vector<int> v;
		vector<bool> visit(nums.size(), false);

		dfs(0, v, visit, nums, answer);

		return answer;
	}
};