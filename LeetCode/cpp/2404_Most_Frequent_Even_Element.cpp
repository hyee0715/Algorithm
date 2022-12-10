class Solution {
public:
	int mostFrequentEven(vector<int>& nums) {
		int answer = -1;
		unordered_map<int, int> um;
		pair<int, int> min_pair = { 100002, -1 };

		for (int num : nums) {
			um[num]++;
		}

		for (auto m : um) {
			if (m.first % 2 == 0) {
				if (m.second > min_pair.second) {
					min_pair = { m.first, m.second };
					continue;
				}

				if (m.second == min_pair.second) {
					if (m.first < min_pair.first) {
						min_pair = { m.first, m.second };
					}
				}
			}
		}

		if (min_pair.first != 100002) {
			answer = min_pair.first;
		}

		return answer;
	}
};