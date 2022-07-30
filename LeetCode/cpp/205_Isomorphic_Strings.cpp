class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> um1, um2;
		string temp;

		for (int i = 0; i < s.size(); i++) {
			um1[s[i]] = t[i];
			um2[t[i]] = s[i];
		}

		for (int i = 0; i < s.size(); i++) {
			temp += um1[s[i]];
		}

		if (temp != t)
			return false;

		temp.clear();

		for (int j = 0; j < t.size(); j++) {
			temp += um2[t[j]];
		}

		if (temp != s)
			return false;

		return true;
	}
};