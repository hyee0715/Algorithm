class Solution {
public:
	bool wordPattern(string pattern, string s) {
		unordered_map<char, string> um1;
		unordered_map<string, char> um2;
		vector<string> v;
		string s1, s2;

		string temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				v.push_back(temp);
				temp.clear();
			}
			else {
				temp += s[i];
			}
		}

		if (!temp.empty()) {
			v.push_back(temp);
			temp.clear();
		}

		for (int i = 0; i < pattern.size(); i++) {
			um1[pattern[i]] = v[i];
		}

		for (int i = 0; i < v.size(); i++) {
			um2[v[i]] = pattern[i];
		}

		for (int i = 0; i < pattern.size(); i++) {
			s2 += um1[pattern[i]];

			if (i != pattern.size() - 1) {
				s2 += " ";
			}
		}

		for (int i = 0; i < v.size(); i++) {
			s1 += um2[v[i]];
		}

		if (s1 == pattern && s2 == s)
			return true;

		return false;
	}
};