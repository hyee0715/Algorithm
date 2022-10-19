class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		char c1, c2;
		bool flag = false, one_swap = false;

		if (s1 == s2)
			return true;

		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (one_swap)
					return false;

				if (!flag) {
					c1 = s1[i];
					c2 = s2[i];
					flag = true;
				}
				else {
					if (s1[i] == c2 && s2[i] == c1) {
						one_swap = true;
					}
					else {
						return false;
					}
				}
			}
		}

		if (one_swap)
			return true;

		return false;
	}
};