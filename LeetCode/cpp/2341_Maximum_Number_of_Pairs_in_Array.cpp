class Solution {
public:
	vector<int> numberOfPairs(vector<int>& nums) {
		unordered_map<int, int> um;
		int even_cnt = 0;
		int leftover = 0;
		vector<int> answer;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (auto m : um) {
			while (m.second > 1) {
				um[m.first] = m.second - 2;
				m.second = m.second - 2;

				even_cnt++;
			}

			if (m.second % 2 != 0) {
				leftover++;
			}
		}

		answer.push_back(even_cnt);
		answer.push_back(leftover);

		return answer;
	}
};