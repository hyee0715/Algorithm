class Solution {
public:
	vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
		vector<vector<int>> answer(grid.size() - 2, vector<int>(grid[0].size() - 2));
		priority_queue<int> q;

		for (int i = 0; i < grid.size() - 2; i++) {
			for (int j = 0; j < grid[i].size() - 2; j++) {
				while (!q.empty()) {
					q.pop();
				}

				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						q.push(grid[i + a][j + b]);
					}
				}

				answer[i][j] = q.top();
			}
		}

		return answer;
	}
};