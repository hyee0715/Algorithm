class Solution {
public:
	int minOperations(int n) {
		int answer = 0;

		int num = 0;
		if (n % 2 == 0) {
			num = 2 * (n / 2);
		}
		else {
			num = (2 * (n / 2)) + 1;
		}

		for (int i = 1; i < n; i += 2) {
			answer += (num - i);
		}

		return answer;
	}
};