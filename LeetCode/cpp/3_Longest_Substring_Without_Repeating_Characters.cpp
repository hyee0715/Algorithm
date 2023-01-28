class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1) {
			return s.length();
		}

		int answer = 0;
		unordered_map<char, int> um;

		int left = 0;
		int right = 0;

		um[s[left]]++;

		while (left <= right && right < s.length()) {
			right++;
			um[s[right]]++;

			answer = max(answer, right - left);

			while (um[s[right]] > 1) {
				um[s[left]]--;
				left++;

				answer = max(answer, right - left);
			}
		}

		return answer;
	}
};