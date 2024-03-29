﻿class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.length() == 1) {
			return true;
		}

		if (word.length() == 2) {
			if (word[0] >= 'a' && word[0] <= 'z' && word[1] >= 'A' && word[1] <= 'Z') {
				return false;
			}

			return true;
		}

		if (word[0] >= 'A' && word[0] <= 'Z') {
			if (word[1] >= 'A' && word[1] <= 'Z') {
				for (int i = 2; i < word.length(); i++) {
					if (word[i] < 'A' || word[i] > 'Z') {
						return false;
					}
				}
			}
			else if (word[1] >= 'a' && word[1] <= 'z') {
				for (int i = 2; i < word.length(); i++) {
					if (word[i] < 'a' || word[i] > 'z') {
						return false;
					}
				}
			}
		}
		else if (word[0] >= 'a' && word[0] <= 'z') {
			for (int i = 1; i < word.length(); i++) {
				if (word[i] < 'a' || word[i] > 'z') {
					return false;
				}
			}
		}

		return true;
	}
};