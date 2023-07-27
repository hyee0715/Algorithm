class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		vector<vector<int>> answer;

		if (m * n != original.size()) {
			return answer;
		}

		answer.assign(m, vector<int>(n));

		int idx = 0;
		for (int i = 0; i < answer.size(); i++) {
			for (int j = 0; j < answer[0].size(); j++) {
				answer[i][j] = original[idx++];
			}
		}

		return answer;
	}
};