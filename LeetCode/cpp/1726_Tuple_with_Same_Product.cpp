class Solution {
public:
	int tupleSameProduct(vector<int>& nums) {
		int answer = 0;
		unordered_map<int, vector<pair<int, int>>> um;

		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				um[nums[i] * nums[j]].push_back({ nums[i], nums[j] });
			}
		}

		for (auto m : um) {
			if (m.second.size() > 1) {
				int n = m.second.size();

				int num = (n * (n - 1)) / 2;
				answer += num * 8;
			}
		}

		return answer;
	}
};