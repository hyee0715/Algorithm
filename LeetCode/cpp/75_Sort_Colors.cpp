class Solution {
public:
	int count[3];

	void sortColors(vector<int>& nums) {
		memset(count, 0, sizeof(count));

		for (int i = 0; i < nums.size(); i++) {
			count[nums[i]]++;
		}

		nums.clear();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < count[i]; j++) {
				nums.push_back(i);
			}
		}
	}
};