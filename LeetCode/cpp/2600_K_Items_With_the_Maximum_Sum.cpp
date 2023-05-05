class Solution {
public:
	int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
		int answer = 0;

		if (numOnes <= k) {
			answer += numOnes;
			k -= numOnes;
		}
		else {
			answer += k;
			k = 0;
		}

		if (k == 0) {
			return answer;
		}

		if (numZeros <= k) {
			k -= numZeros;
		}
		else {
			k = 0;
		}

		if (k == 0) {
			return answer;
		}

		if (numNegOnes <= k) {
			answer -= numNegOnes;
			k -= numNegOnes;
		}
		else {
			answer -= k;
		}

		return answer;
	}
};