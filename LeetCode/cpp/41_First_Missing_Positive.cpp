class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		unordered_set<int> s;

		for (int i = 0; i < nums.size(); i++) {
			s.insert(nums[i]);
		}

		int cnt = 1;

		while (1) {
			if (s.find(cnt) == s.end()) {
				break;
			}

			cnt++;
		}

		return cnt;
	}
};