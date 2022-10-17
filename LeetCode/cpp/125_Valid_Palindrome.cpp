class Solution {
public:
	bool isPalindrome(string s) {
		string palin;

		for (int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]);

			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
				palin += s[i];
			}
		}

		int left = 0;
		int right = palin.size() - 1;

		while (left < right) {
			if (palin[left] == palin[right]) {
				left++;
				right--;
			}
			else {
				return false;
			}
		}

		return true;
	}
};