class Solution {
public:
	vector<int> leftRigthDifference(vector<int>& nums) {
		vector<int> left, right, answer;

		left.push_back(0);
		for (int i = 0; i < nums.size() - 1; i++) {
			left.push_back(left[left.size() - 1] + nums[i]);
		}

		right.push_back(0);
		for (int i = nums.size() - 1; i > 0; i--) {
			right.push_back(right[right.size() - 1] + nums[i]);
		}

		reverse(right.begin(), right.end());

		for (int i = 0; i < left.size(); i++) {
			answer.push_back(abs(left[i] - right[i]));
		}

		return answer;
	}
};