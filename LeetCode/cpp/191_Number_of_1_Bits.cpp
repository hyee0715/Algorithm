class Solution {
public:
	int hammingWeight(uint32_t n) {
		int answer = 0;
		long long num = n;

		while (num > 0) {
			if (num % 2 != 0) {
				answer++;
			}

			num /= 2;
		}

		return answer;
	}
};