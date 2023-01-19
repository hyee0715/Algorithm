class Solution {
public:
	int minBitFlips(int start, int goal) {
		int num = start ^ goal;
		int answer = 0;

		while (num > 0) {
			num = num & (num - 1);
			answer++;
		}

		return answer;
	}
};