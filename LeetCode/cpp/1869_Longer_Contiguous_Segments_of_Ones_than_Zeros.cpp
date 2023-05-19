class Solution {
public:
	int findLongestLength(string s, char c) {
		int cnt = 1;
		int maxNum = 0;

		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == s[i + 1] && s[i] == c) {
				cnt++;
				maxNum = max(maxNum, cnt);
			}
			else {
				cnt = 1;
			}
		}

		return maxNum;
	}

	bool checkZeroOnes(string s) {
		if (s.length() == 1) {
			if (s[0] == '1') {
				return true;
			}
		}

		int oneLongestLength = findLongestLength(s, '1');
		int zeroLongestLength = findLongestLength(s, '0');

		if (oneLongestLength > zeroLongestLength) {
			return true;
		}

		return false;
	}
};