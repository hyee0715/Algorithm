class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		vector<vector<int>> answer(rowSum.size(), vector<int>(colSum.size(), 0));

		vector<int> curColSum(colSum.size(), 0);
		vector<int> prevColSum(colSum.size(), 0);

		for (int i = 0; i < rowSum.size(); i++) {
			for (int j = 0; j < colSum.size(); j++) {
				if (curColSum[j] < colSum[j] && rowSum[i] > 0) {
					if (rowSum[i] <= (colSum[j] - curColSum[j])) {
						curColSum[j] += rowSum[i];
						rowSum[i] = 0;
					}
					else {
						rowSum[i] -= (colSum[j] - curColSum[j]);
						curColSum[j] += (colSum[j] - curColSum[j]);
					}
				}
			}

			for (int j = 0; j < curColSum.size(); j++) {
				answer[i][j] = curColSum[j] - prevColSum[j];

				prevColSum[j] = curColSum[j];
			}
		}

		return answer;
	}
};