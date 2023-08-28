class Solution {
public:
	bool isAcronym(vector<string>& words, string s) {
		string w;
		for (string word : words) {
			w += word[0];
		}

		if (s == w) {
			return true;
		}

		return false;
	}
};