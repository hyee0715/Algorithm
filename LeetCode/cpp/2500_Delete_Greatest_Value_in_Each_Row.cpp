class Solution {
public:
	int deleteGreatestValue(vector<vector<int>>& grid) {
		int answer = 0;

		for (int i = 0; i < grid.size(); i++) {
			sort(grid[i].begin(), grid[i].end(), greater<>());
		}

		for (int i = 0; i < grid[0].size(); i++) {
			int max_num = -1;

			for (int j = 0; j < grid.size(); j++) {
				max_num = max(max_num, grid[j][i]);
				grid[j][i] = -1;
			}

			answer += max_num;
		}

		return answer;
	}
};