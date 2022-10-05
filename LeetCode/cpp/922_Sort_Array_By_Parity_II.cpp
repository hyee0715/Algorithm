class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		vector<int> even, odd, answer;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] % 2 == 0) {
				even.push_back(nums[i]);
			}
			else {
				odd.push_back(nums[i]);
			}
		}

		for (int i = 0; i < nums.size(); i++) {
			if (i % 2 == 0) {
				answer.push_back(even[even.size() - 1]);
				even.pop_back();
			}
			else {
				answer.push_back(odd[odd.size() - 1]);
				odd.pop_back();
			}
		}

		return answer;
	}
};