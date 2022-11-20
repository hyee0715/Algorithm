class Solution {
public:
	string largestOddNumber(string num) {
		string answer;
		int idx = -1;

		for (int i = num.size() - 1; i >= 0; i--) {
			if ((num[i] - '0') % 2 != 0) {
				idx = i;
				break;
			}
		}

		for (int i = 0; i <= idx; i++) {
			answer += num[i];
		}

		return answer;
	}
};