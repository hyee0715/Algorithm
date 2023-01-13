class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if (s.size() <= k) {
			return s.size();
		}

		unordered_map<char, int> um;
		int answer = -1;

		int left = 0;
		int right = 0;

		while (right < s.size()) {
			um[s[right]] = right;
			right++;

			if (um.size() > k) {
				int min_idx = 50002;
				for (auto m : um) {
					min_idx = min(min_idx, m.second);
				}

				um.erase(s[min_idx]);
				left = min_idx + 1;
			}

			answer = max(answer, (right - left));
		}

		return answer;
	}
};