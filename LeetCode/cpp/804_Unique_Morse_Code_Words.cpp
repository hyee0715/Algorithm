class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		string alphabet[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

		unordered_map<char, string> um;
		unordered_map<string, int> result;

		for (int i = 0; i < 26; i++) {
			um[i + 'a'] = alphabet[i];
		}

		for (int i = 0; i < words.size(); i++) {
			string transformation;

			for (int j = 0; j < words[i].size(); j++) {
				transformation += um[words[i][j]];
			}

			result[transformation]++;
		}

		return result.size();
	}
};