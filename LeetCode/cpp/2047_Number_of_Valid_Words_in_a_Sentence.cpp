class Solution {
public:
	int countValidWords(string sentence) {
		int answer = 0;
		vector<string> words;

		string temp;
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] == ' ' && !temp.empty()) {
				words.push_back(temp);
				temp.clear();

				continue;
			}

			if (sentence[i] != ' ') {
				temp += sentence[i];
			}
		}

		if (!temp.empty()) {
			words.push_back(temp);
		}

		for (string word : words) {
			bool hyphen = false;
			bool punctuationMark = false;

			bool valid = true;
			for (int i = 0; i < word.length(); i++) {
				if (word[i] >= '0' && word[i] <= '9') {
					valid = false;
					break;
				}

				if (word[i] == '-') {
					if (i == 0 || i == word.length() - 1 || hyphen) {
						valid = false;
						break;
					}

					if (word[i - 1] == '.' || word[i - 1] == ',' || word[i - 1] == '!' || word[i - 1] == '-' || word[i + 1] == '.' || word[i + 1] == ',' || word[i + 1] == '!' || word[i + 1] == '-') {
						valid = false;
						break;
					}

					hyphen = true;
				}

				if (word[i] == '.' || word[i] == ',' || word[i] == '!') {
					if (punctuationMark || i != word.length() - 1) {
						valid = false;
						break;
					}

					punctuationMark = true;
				}
			}

			if (valid) {
				answer++;
			}
		}

		return answer;
	}
};