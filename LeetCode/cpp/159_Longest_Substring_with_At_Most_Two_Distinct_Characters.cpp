class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		if (s.length() <= 2) {
			return s.length();
		}

		int answer = -1;
		unordered_map<char, int> um;

		int left = 0;
		int right = 1;

		um[s[left]]++;
		um[s[right]]++;

		while (right < s.length() - 1) {
			right++;
			um[s[right]]++;

			while (um.size() > 2) {
				um[s[left]]--;

				if (um[s[left]] == 0) {
					um.erase(s[left]);
				}

				left++;
			}

			int sum = 0;
			for (auto m : um) {
				sum += m.second;
			}

			answer = max(answer, sum);
		}

		return answer;
	}
};