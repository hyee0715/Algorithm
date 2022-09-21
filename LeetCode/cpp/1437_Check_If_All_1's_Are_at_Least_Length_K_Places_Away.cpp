class Solution {
public:
	bool kLengthApart(vector<int>& nums, int k) {
		int cnt = 0;
		bool flag = false;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				if (cnt < k && flag)
					return false;

				flag = true;
				cnt = 0;
			}
			else {
				cnt++;
			}
		}

		return true;
	}
};