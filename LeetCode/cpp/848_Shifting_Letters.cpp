class Solution {
public:
	string shiftingLetters(string s, vector<int>& shifts) {
		vector<int> culSum(shifts.size(), 0);
		culSum[culSum.size() - 1] = shifts[shifts.size() - 1];

		for (int i = shifts.size() - 2; i >= 0; i--) {
			culSum[i] = (shifts[i] + culSum[i + 1]) % 26;
		}

		for (int i = 0; i < s.length(); i++) {
			int n = s[i] + (culSum[i] % 26);

			if (n > 122) {
				n -= 26;
			}

			s[i] = n;
		}

		return s;
	}
};