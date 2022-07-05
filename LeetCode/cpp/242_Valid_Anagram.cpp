class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> um;

		for (int i = 0; i < s.size(); i++)
			um[s[i]]++;

		for (int i = 0; i < t.size(); i++) {
			if (um[t[i]] == 0)
				return false;
			else
				um[t[i]]--;
		}

		for (auto m : um) {
			if (m.second != 0)
				return false;
		}

		return true;
	}
};