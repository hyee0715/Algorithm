class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
		int answer = 0;
		queue<pair<int, int>> q;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == '0') {
					q.push({ i, j });
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			int cnt = 0;

			//up
			for (int i = x - 1; i >= 0; i--) {
				if (i < 0 || grid[i][y] == 'W') {
					break;
				}

				if (grid[i][y] == 'E') {
					cnt++;
				}
			}

			//down
			for (int i = x + 1; i < grid.size(); i++) {
				if (i >= grid.size() || grid[i][y] == 'W') {
					break;
				}

				if (grid[i][y] == 'E') {
					cnt++;
				}
			}

			//left
			for (int i = y - 1; i >= 0; i--) {
				if (i < 0 || grid[x][i] == 'W') {
					break;
				}

				if (grid[x][i] == 'E') {
					cnt++;
				}
			}

			//right
			for (int i = y + 1; i < grid[0].size(); i++) {
				if (i >= grid[0].size() || grid[x][i] == 'W') {
					break;
				}

				if (grid[x][i] == 'E') {
					cnt++;
				}
			}

			answer = max(answer, cnt);
		}

		return answer;
	}
};