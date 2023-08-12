class Solution {
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> answer;

		unordered_map<char, char> um1, um2;

		for (string word : words) {
			for (int i = 0; i < word.length(); i++) {
				um1[word[i]] = pattern[i];
				um2[pattern[i]] = word[i];
			}

			string w1, w2;

			for (int i = 0; i < word.length(); i++) {
				w1 += um1[word[i]];
				w2 += um2[pattern[i]];
			}

			if (w1 == pattern && w2 == word) {
				answer.push_back(word);
			}
		}

		return answer;
	}
};