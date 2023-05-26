class Solution {
public:
	int countPairs(vector<int>& nums, int k) {
		int answer = 0;

		unordered_map<int, vector<int>> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]].push_back(i);
		}

		for (auto m : um) {
			vector<int> v = m.second;

			for (int i = 0; i < v.size() - 1; i++) {
				for (int j = i + 1; j < v.size(); j++) {
					if ((v[i] * v[j]) % k == 0) {
						answer++;
					}
				}
			}
		}

		return answer;
	}
};