class Solution {
public:
	int minFlips(string target) {
		int answer = 0;

		char current = '0';

		for (int i = 0; i < target.length(); i++) {
			if (target[i] != current) {
				if (current == '0') {
					current = '1';
				}
				else {
					current = '0';
				}

				answer++;
			}
		}

		return answer;
	}
};