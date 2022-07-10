class Solution {
public:
	bool canPermutePalindrome(string s) {
		unordered_map<char, int> um;
		int odd = 0;

		for (int i = 0; i < s.size(); i++) {
			um[s[i]]++;
		}

		for (auto pair : um) {
			if (pair.second % 2 == 1) {
				odd++;
			}

			if (odd > 1)
				return false;
		}

		return true;
	}
};