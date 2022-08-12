class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> um;
		int answer = -1;

		for (int i = 0; i < s.size(); i++) {
			um[s[i]]++;
		}

		for (int i = 0; i < s.size(); i++) {
			if (um[s[i]] == 1) {
				answer = i;
				break;
			}
		}

		return answer;
	}
};