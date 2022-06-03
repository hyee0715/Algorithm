class Solution {
public:
	bool checkRecord(string s) {
		int A_cnt = 0, L_cnt = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A') {
				A_cnt++;
			}

			if (A_cnt >= 2) {
				return false;
			}

			if (s[i] == 'L') {
				L_cnt++;
			}
			else {
				L_cnt = 0;
			}

			if (L_cnt > 2) {
				return false;
			}
		}

		return true;
	}
};