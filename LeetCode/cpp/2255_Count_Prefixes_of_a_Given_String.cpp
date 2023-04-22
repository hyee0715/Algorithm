class Solution {
public:
	int countPrefixes(vector<string>& words, string s) {
		int answer = 0;

		unordered_map<string, int> um;

		for (string word : words) {
			um[word]++;
		}

		string prefix;
		for (int i = 0; i < s.length(); i++) {
			prefix += s[i];

			if (um.count(prefix) != 0) {
				answer += um[prefix];
			}
		}

		return answer;
	}
};