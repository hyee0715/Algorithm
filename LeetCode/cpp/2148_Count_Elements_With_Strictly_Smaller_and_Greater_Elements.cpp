class Solution {
public:
	int countElements(vector<int>& nums) {
		int answer = 0;

		map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		int idx = 0;

		for (auto m : um) {
			if (idx != 0 && idx != um.size() - 1) {
				answer += m.second;
			}

			idx++;
		}

		return answer;
	}
};