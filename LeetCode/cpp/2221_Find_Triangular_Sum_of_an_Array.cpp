class Solution {
public:
	int triangularSum(vector<int>& nums) {
		int answer = 0;

		vector<int> v;

		while (nums.size() > 1) {
			for (int i = 0; i < nums.size() - 1; i++) {
				v.push_back((nums[i] + nums[i + 1]) % 10);
			}

			nums.clear();
			for (int n : v) {
				nums.push_back(n);
			}

			v.clear();
		}

		answer = nums[0];
		return answer;
	}
};