class Solution {
public:
	string makeFancyString(string s) {
		string ret;

		int cnt = 1;
		char pre = s[0];
		ret += pre;

		for (int i = 1; i < s.size(); i++) {
			if (s[i] == pre) {
				cnt++;

				if (cnt >= 3) {
					continue;
				}

			}
			else {
				pre = s[i];
				cnt = 1;
			}

			ret += s[i];
		}

		return ret;
	}
};