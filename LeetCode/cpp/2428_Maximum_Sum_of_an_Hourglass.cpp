class Solution {
public:
	int maxSum(vector<vector<int>>& grid) {
		int answer = 0;

		int dx[] = { 0, 0, 0, 1, 2, 2, 2 };
		int dy[] = { 0, 1, 2, 1, 0, 1, 2 };

		for (int i = 0; i <= grid.size() - 3; i++) {
			for (int j = 0; j <= grid[i].size() - 3; j++) {
				int sum = 0;

				for (int k = 0; k < 7; k++) {
					sum += grid[i + dx[k]][j + dy[k]];
				}

				answer = max(answer, sum);
			}
		}

		return answer;
	}
};