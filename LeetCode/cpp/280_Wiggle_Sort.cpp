class Solution {
public:
	void swap(int i, int j, vector<int>& nums) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 1; i++) {
			if (i % 2 != 0) {
				swap(i, i + 1, nums);
			}
		}
	}
};