class Solution {
public:
	int getMinDistance(vector<int>& nums, int target, int start) {
		vector<int> indexes;
		int answer = nums.size();

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				indexes.push_back(i);
			}
		}

		for (int index : indexes) {
			answer = min(answer, abs(index - start));
		}

		return answer;
	}
};