class Solution {
public:
	bool areOccurrencesEqual(string s) {
		unordered_map<char, int> um;

		for (int i = 0; i < s.size(); i++) {
			um[s[i]]++;
		}

		int cnt = um[s[0]];

		for (auto m : um) {
			if (cnt != m.second) {
				return false;
			}
		}

		return true;
	}
};