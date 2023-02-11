class Solution {
public:
	void check(vector<vector<int>>& matrix, vector<int>& answer, vector<vector<bool>>& visit, int mStart, int nStart, int mSize, int nSize) {
		if (mStart >= mSize || nStart >= nSize) {
			return;
		}

		if (mSize - mStart == 1 && nSize - mStart == 1) {
			if (visit[mStart][nStart] == false) {
				visit[mStart][nStart] = true;
				answer.push_back(matrix[mStart][nStart]);
			}

			return;
		}

		for (int i = nStart; i < nSize; i++) {
			if (visit[mStart][i] == false) {
				visit[mStart][i] = true;
				answer.push_back(matrix[mStart][i]);
			}
		}

		for (int i = mStart; i < mSize; i++) {
			if (visit[i][nSize - 1] == false) {
				visit[i][nSize - 1] = true;
				answer.push_back(matrix[i][nSize - 1]);
			}
		}

		for (int i = nSize - 1; i >= nStart; i--) {
			if (visit[mSize - 1][i] == false) {
				visit[mSize - 1][i] = true;
				answer.push_back(matrix[mSize - 1][i]);
			}
		}

		for (int i = mSize - 1; i >= mStart; i--) {
			if (visit[i][nStart] == false) {
				visit[i][nStart] = true;
				answer.push_back(matrix[i][nStart]);
			}
		}

		check(matrix, answer, visit, mStart + 1, nStart + 1, mSize - 1, nSize - 1);
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> answer;
		vector<vector<bool>> visit(matrix.size(), vector<bool>(matrix[0].size(), false));

		check(matrix, answer, visit, 0, 0, matrix.size(), matrix[0].size());

		return answer;
	}
};