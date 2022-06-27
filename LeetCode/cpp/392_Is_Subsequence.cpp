class Solution {
public:
	bool isSubsequence(string s, string t) {
		int t_start = 0;
		bool found = false;

		for (int i = 0; i < s.size(); i++) {
			found = false;

			for (int j = t_start; j < t.size(); j++) {
				if (s[i] == t[j]) {
					t_start = j + 1;
					found = true;
					break;
				}
			}

			if (!found)
				return false;
		}

		return true;
	}
};