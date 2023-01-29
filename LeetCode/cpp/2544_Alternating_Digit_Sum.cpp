class Solution {
public:
	int alternateDigitSum(int n) {
		int answer = 0;

		string num = to_string(n);

		for (int i = 0; i < num.length(); i++) {
			if (i % 2 == 0) {
				answer += (num[i] - '0');
				continue;
			}

			answer -= (num[i] - '0');
		}

		return answer;
	}
};