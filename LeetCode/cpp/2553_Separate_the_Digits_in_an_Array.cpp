class Solution {
public:
	vector<int> separateDigits(vector<int>& nums) {
		vector<int> answer;

		for (int num : nums) {
			string s = to_string(num);

			for (int i = 0; i < s.length(); i++) {
				answer.push_back(s[i] - '0');
			}
		}

		return answer;
	}
};