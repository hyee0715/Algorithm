class Solution {
public:
	bool allZero(vector<int>& arr) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] != 0) {
				return false;
			}
		}

		return true;
	}

	bool canThreePartsEqualSum(vector<int>& arr) {
		if (allZero(arr)) {
			return true;
		}

		int totalSum = 0;

		for (int i = 0; i < arr.size(); i++) {
			totalSum += arr[i];
		}

		if (totalSum % 3 != 0) {
			return false;
		}

		int dividedSum = totalSum / 3;
		int cnt = 0, currentSum = 0;
		vector<int> cumSum;
		cumSum.push_back(arr[0]);

		for (int i = 1; i < arr.size(); i++) {
			cumSum.push_back(arr[i] + cumSum[i - 1]);
		}

		for (int i = 0; i < cumSum.size(); i++) {
			if (cnt == 0 && cumSum[i] == dividedSum) {
				cnt++;
				currentSum = cumSum[i];
				continue;
			}

			if (cumSum[i] - currentSum == dividedSum) {
				cnt++;
				currentSum = cumSum[i];
			}
		}

		if (cnt >= 3) {
			return true;
		}

		return false;
	}
};