﻿class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> um;

		for (int i = 0; i < magazine.size(); i++) {
			um[magazine[i]]++;
		}

		for (int i = 0; i < ransomNote.size(); i++) {
			if (um[ransomNote[i]] >= 1)
				um[ransomNote[i]]--;
			else
				return false;
		}

		return true;
	}
};