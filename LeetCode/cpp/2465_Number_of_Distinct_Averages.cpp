class Solution {
public:
	int distinctAverages(vector<int>& nums) {
		unordered_map<double, int> um;

		while (nums.size() > 0) {
			sort(nums.begin(), nums.end());

			int minNum = nums[0];
			int maxNum = nums[nums.size() - 1];

			nums.erase(nums.begin());
			nums.pop_back();

			double avg = (double)(minNum + maxNum) / 2;
			um[avg]++;
		}

		return um.size();
	}
};