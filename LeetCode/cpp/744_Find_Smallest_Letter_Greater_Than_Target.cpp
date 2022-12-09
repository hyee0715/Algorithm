class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		char answer = letters[0];

		for (char letter : letters) {
			if (letter > target) {
				answer = letter;
				return answer;
			}
		}

		return answer;
	}
};