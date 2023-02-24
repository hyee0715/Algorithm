class Solution {
public:
	bool isPalindrome(string s) {
		string rev(s);

		reverse(rev.begin(), rev.end());

		if (s == rev) {
			return true;
		}

		return false;
	}

	string breakPalindrome(string palindrome) {
		if (palindrome.length() == 1) {
			return "";
		}

		string temp = palindrome;

		for (int j = 0; j < 26; j++) {
			for (int i = 0; i < temp.length(); i++) {
				temp = palindrome;

				if (temp[i] == 'a') {
					temp[temp.length() - 1 - i] = 'a' + j;
				}
				else {
					temp[i] = 'a' + j;
				}

				if (!isPalindrome(temp)) {
					return temp;
				}
			}
		}

		return temp;
	}
};