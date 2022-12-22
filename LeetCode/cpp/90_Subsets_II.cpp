class Solution {
public:
	void dfs(int idx, int cnt, vector<bool>& visit, vector<int>& v, set<vector<int>>& st, int limit, vector<int>& nums) {
		if (cnt == limit) {
			st.insert(v);
			return;
		}
		else {
			for (int i = idx; i < nums.size(); i++) {
				if (visit[i] == true) continue;
				visit[i] = true;
				v.push_back(nums[i]);
				dfs(i, cnt + 1, visit, v, st, limit, nums);
				v.pop_back();
				visit[i] = false;
			}
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<bool> visit(nums.size(), false);
		vector<int> v;
		set<vector<int>> st;
		vector<vector<int>> answer;

		sort(nums.begin(), nums.end());

		for (int i = 0; i <= nums.size(); i++) {
			dfs(0, 0, visit, v, st, i, nums);
		}

		for (auto s : st) {
			answer.push_back(s);
		}

		return answer;
	}
};