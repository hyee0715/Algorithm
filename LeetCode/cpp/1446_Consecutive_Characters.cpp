class Solution {
public:
	int maxPower(string s) {
		int result = 1;
		int cnt = 1;

		for (int i = 1; i < s.size(); i++) {
			if (s[i - 1] == s[i]) {
				cnt++;
				result = max(result, cnt);
			}
			else {
				cnt = 1;
			}
		}

		return result;
	}
};