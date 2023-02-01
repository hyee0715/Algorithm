class Solution {
public:
	int minMoves(int target, int maxDoubles) {
		if (maxDoubles == 0) {
			return target - 1;
		}

		int answer = 0;
		bool stop = false;

		while (target > 1) {
			while (target % 2 == 0 && maxDoubles > 0) {
				target /= 2;
				maxDoubles--;
				answer++;

				if (target == 1) {
					return answer;
				}
			}

			if (maxDoubles == 0) {
				return answer + target - 1;
			}

			target--;
			answer++;

			if (target == 1) {
				break;
			}
		}

		return answer;
	}
};