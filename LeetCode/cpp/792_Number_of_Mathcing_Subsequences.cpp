class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		unordered_map<char, vector<string>> um;
		int answer = 0;

		for (int i = 0; i < words.size(); i++) {
			um[words[i][0]].push_back(words[i]);
		}

		for (int i = 0; i < s.length(); i++) {
			vector<string> words = um[s[i]];
			um.erase(s[i]);

			for (int j = 0; j < words.size(); j++) {
				string word = words[j];

				word = word.substr(1);

				if (word.length() == 0) {
					answer++;
					continue;
				}

				um[word[0]].push_back(word);
			}
		}

		return answer;
	}
};