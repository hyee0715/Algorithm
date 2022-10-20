class Solution {
public:
	int arrangeCoins(int n) {
		int answer = 0, cnt = 1;

		while (n - cnt >= 0) {
			n = n - cnt;
			cnt++;
			answer++;
		}

		return answer;
	}
};