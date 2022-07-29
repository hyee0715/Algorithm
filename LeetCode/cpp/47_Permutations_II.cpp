class Solution {
public:
	void dfs(int cnt, vector<int>& nums, vector<vector<int>>& answer, vector<int>& v, vector<bool>& visit) {
		if (cnt == nums.size()) {
			answer.push_back(v);
		}
		else {
			for (int i = 0; i < nums.size(); i++) {
				if (visit[i] == true) continue;
				visit[i] = true;
				v.push_back(nums[i]);
				dfs(cnt + 1, nums, answer, v, visit);
				v.pop_back();
				visit[i] = false;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> answer;
		vector<int> v;
		vector<bool> visit(9, false);
		set<vector<int>> st;

		dfs(0, nums, answer, v, visit);

		for (int i = 0; i < answer.size(); i++) {
			if (st.find(answer[i]) == st.end())
				st.insert(answer[i]);
		}

		answer.clear();

		for (auto s : st) {
			answer.push_back(s);
		}

		return answer;
	}
};