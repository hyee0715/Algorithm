class Solution {
public:
	vector<int> distinctDifferenceArray(vector<int>& nums) {
		vector<int> answer;

		unordered_map<int, int> prefix, suffix;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (j <= i) {
					prefix[nums[j]]++;
				}
				else {
					suffix[nums[j]]++;
				}
			}

			answer.push_back(prefix.size() - suffix.size());

			prefix.clear();
			suffix.clear();
		}

		return answer;
	}
};