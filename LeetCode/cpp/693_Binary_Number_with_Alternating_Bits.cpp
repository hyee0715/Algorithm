class Solution {
public:
	bool hasAlternatingBits(int n) {

		string s;

		while (n > 0) {
			int a = (n % 2);
			s += a + '0';

			n = n / 2;
		}

		reverse(s.begin(), s.end());

		for (int i = 1; i < s.size(); i++) {
			if (s[i - 1] == s[i])
				return false;
		}

		return true;
	}
};