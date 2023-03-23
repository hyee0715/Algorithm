class Solution {
public:
	bool checkAlmostEquivalent(string word1, string word2) {
		unordered_map<char, int> um1, um2;

		for (int i = 0; i < word1.length(); i++) {
			um1[word1[i]]++;
		}

		for (int i = 0; i < word2.length(); i++) {
			um2[word2[i]]++;
		}

		for (auto m : um1) {
			if (abs(um2[m.first] - m.second) > 3) {
				return false;
			}
		}

		for (auto m : um2) {
			if (abs(um1[m.first] - m.second) > 3) {
				return false;
			}
		}

		return true;
	}
};