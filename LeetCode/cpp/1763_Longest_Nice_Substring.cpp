class Solution {
public:
	bool check(unordered_map<char, int> low, unordered_map<char, int> hi) {
		for (auto m : low) {
			if (hi[m.first - 32] == 0) {
				return false;
			}
		}

		for (auto m : hi) {
			if (low[m.first + 32] == 0) {
				return false;
			}
		}

		return true;
	}

	string longestNiceSubstring(string s) {
		unordered_map<char, int> low, hi;
		string answer;

		for (int i = 0; i < s.length(); i++) {
			low.clear();
			hi.clear();

			for (int j = i; j < s.length(); j++) {
				if (s[j] >= 'a' && s[j] <= 'z') {
					low[s[j]]++;
				}
				else {
					hi[s[j]]++;
				}

				if (check(low, hi)) {
					if (j - i + 1 > answer.length()) {
						answer = s.substr(i, j - i + 1);
					}
				}
			}
		}

		return answer;
	}
};