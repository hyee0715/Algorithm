class Solution {
public:
	bool rotateString(string s, string goal) {
		for (int i = 0; i < s.size(); i++) {
			string ns = s.substr(1, s.size() - 1);
			ns = ns + s[0];

			if (ns == goal)
				return true;

			s = ns;
		}

		return false;
	}
};