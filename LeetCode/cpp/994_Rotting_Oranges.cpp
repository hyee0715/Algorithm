class Solution {
public:
	int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, queue<pair<int, int>>& q) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };
		int cnt = 0;

		while (!q.empty()) {
			int qs = q.size();

			for (int k = 0; k < qs; k++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;

					if (grid[nx][ny] == 1 && visit[nx][ny] == false) {
						q.push({ nx, ny });
						visit[nx][ny] = true;
						grid[nx][ny] = 2;
					}
				}
			}

			if (!q.empty())
				cnt++;
		}

		return cnt;
	}

	int orangesRotting(vector<vector<int>>& grid) {
		int count = 0;
		vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
		queue<pair<int, int>> q;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 2) {
					q.push({ i, j });
					visit[i][j] = true;
				}
			}
		}

		count = bfs(grid, visit, q);

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1)
					return -1;
			}
		}

		return count;
	}
};