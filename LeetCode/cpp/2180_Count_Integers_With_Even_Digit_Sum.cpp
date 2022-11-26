class Solution {
public:
	int countEven(int num) {
		int answer = 0;

		for (int i = 1; i <= num; i++) {
			string s = to_string(i);

			int sum = 0;
			for (int j = 0; j < s.size(); j++) {
				sum += s[j] - '0';
			}

			if (sum % 2 == 0) {
				answer++;
			}
		}

		return answer;
	}
};