class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		string answer;

		if (word1.size() > word2.size()) {
			for (int i = 0; i < word2.size(); i++) {
				answer += word1[i];
				answer += word2[i];
			}

			for (int i = word2.size(); i < word1.size(); i++) {
				answer += word1[i];
			}
		}
		else {
			for (int i = 0; i < word1.size(); i++) {
				answer += word1[i];
				answer += word2[i];
			}

			for (int i = word1.size(); i < word2.size(); i++) {
				answer += word2[i];
			}
		}

		return answer;
	}
};