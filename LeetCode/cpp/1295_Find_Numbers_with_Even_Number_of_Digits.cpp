class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int answer = 0;

		for (int i = 0; i < nums.size(); i++) {
			string s = to_string(nums[i]);
			int cnt = s.size();

			if (cnt % 2 == 0)
				answer++;
		}

		return answer;
	}
};