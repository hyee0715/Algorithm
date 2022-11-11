class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		unordered_map<int, int> um;
		int answer = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (um[nums[i]] == 0) {
				um[nums[i]]++;
				continue;
			}

			nums[i] = 101;
		}

		sort(nums.begin(), nums.end());

		answer = um.size();

		return answer;
	}
};