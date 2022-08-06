class Solution {
public:
	char repeatedCharacter(string s) {
		unordered_map<char, int> um;
		char answer;

		for (int i = 0; i < s.size(); i++) {
			um[s[i]]++;

			if (um[s[i]] == 2) {
				answer = s[i];
				break;
			}
		}

		return answer;
	}
};