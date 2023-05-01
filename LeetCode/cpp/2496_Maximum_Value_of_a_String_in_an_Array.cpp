class Solution {
public:
	bool allDigits(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] < '0' || s[i] > '9') {
				return false;
			}
		}

		return true;
	}

	int maximumValue(vector<string>& strs) {
		int answer = 0;

		for (string s : strs) {
			if (allDigits(s)) {
				answer = max(answer, stoi(s));
			}
			else {
				int n = s.length();
				answer = max(answer, n);
			}
		}

		return answer;
	}
};