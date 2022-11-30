class Solution {
public:
	bool isSumEqual(string firstWord, string secondWord, string targetWord) {
		vector<char> alphabet;
		for (int i = 0; i < 26; i++) {
			alphabet.push_back(i + '0');
		}

		for (int i = 0; i < firstWord.size(); i++) {
			firstWord[i] = alphabet[firstWord[i] - 'a'];
		}

		for (int i = 0; i < secondWord.size(); i++) {
			secondWord[i] = alphabet[secondWord[i] - 'a'];
		}

		for (int i = 0; i < targetWord.size(); i++) {
			targetWord[i] = alphabet[targetWord[i] - 'a'];
		}

		long long first = stol(firstWord);
		long long second = stol(secondWord);

		long long sum = first + second;

		if (sum == stol(targetWord)) {
			return true;
		}

		return false;
	}
};