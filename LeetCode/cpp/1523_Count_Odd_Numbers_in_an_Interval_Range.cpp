class Solution {
public:
	int countOdds(int low, int high) {
		int answer = 0;

		if (low % 2 == 0)
			low++;

		if (high % 2 == 0)
			high--;

		for (int i = low; i <= high; i += 2) {
			answer++;
		}

		return answer;
	}
};