class Solution {
public:
	int longestRepeatingSubstring(string s) {
		int answer = 0;
		unordered_map<string, int> um;

		for (int i = s.length() - 1; i >= 2; i--) {
			um.clear();

			string temp;

			for (int j = 0; j < i; j++) {
				temp += s[j];
			}

			um[temp]++;

			temp.erase(0, 1);

			for (int j = i; j < s.length(); j++) {
				temp += s[j];

				um[temp]++;
				temp.erase(0, 1);
			}

			for (auto m : um) {
				if (m.second > 1) {
					if (answer < m.first.length()) {
						answer = m.first.length();
					}
				}
			}

			if (answer > 0) {
				break;
			}
		}

		return answer;
	}
};