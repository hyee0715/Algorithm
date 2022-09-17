class Solution {
public:
	bool checkIfPangram(string sentence) {
		vector<bool> alphabet(26, false);

		for (int i = 0; i < sentence.size(); i++) {
			alphabet[sentence[i] - 'a'] = true;
		}

		for (int i = 0; i < alphabet.size(); i++) {
			if (alphabet[i] == false)
				return false;
		}

		return true;
	}
};