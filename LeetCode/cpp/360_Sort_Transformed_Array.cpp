class Solution {
public:
	vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
		vector<int> answer;

		for (int i = 0; i < nums.size(); i++) {
			int result = a * nums[i] * nums[i] + b * nums[i] + c;
			answer.push_back(result);
		}

		sort(answer.begin(), answer.end());

		return answer;
	}
};