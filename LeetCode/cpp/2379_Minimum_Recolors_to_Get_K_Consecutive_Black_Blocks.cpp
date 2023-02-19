class Solution {
public:
	int minimumRecolors(string blocks, int k) {
		int answer = INT_MAX, cnt = 0;

		for (int i = 0; i < blocks.length() - k + 1; i++) {
			cnt = 0;

			for (int j = i; j < i + k; j++) {
				if (blocks[j] == 'W') {
					cnt++;
				}
			}

			answer = min(answer, cnt);
		}

		return answer;
	}
};