class Solution {
public:
	vector<int> getConcatenation(vector<int>& nums) {
		vector<int> answer;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < nums.size(); j++) {
				answer.push_back(nums[j]);
			}
		}

		return answer;
	}
};