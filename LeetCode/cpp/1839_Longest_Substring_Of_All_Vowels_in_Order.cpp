class Solution {
public:
	int longestBeautifulSubstring(string word) {
		int answer = 0;
		int cnt = 0;
		int currentLength = 0;

		for (int i = 0; i < word.length(); i++) {
			if (word[i] == 'a') {
				cnt++;
				currentLength++;
				char curChar = word[i];

				for (int j = i + 1; j < word.length(); j++) {
					if (curChar == word[j]) {
						currentLength++;
					}
					else if (curChar < word[j]) {
						currentLength++;
						curChar = word[j];
						cnt++;
					}
					else {
						cnt = 0;
						currentLength = 0;

						break;
					}

					if (cnt == 5) {
						answer = max(answer, currentLength);
					}

					i++;
				}
			}
		}

		return answer;
	}
};