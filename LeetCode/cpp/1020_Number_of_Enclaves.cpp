class Solution {
public:
	int check(vector<vector<int>>& grid, vector<vector<bool>>& visit, int a, int b) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		queue<pair<int, int>> q;
		q.push({ a, b });
		visit[a][b] = true;

		int cnt = 0;
		bool boundary = false;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			cnt++;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) {
					if (grid[x][y] == 1) {
						boundary = true;
					}

					continue;
				}

				if (grid[nx][ny] == 1 && visit[nx][ny] == false) {
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}

		if (boundary) {
			return 0;
		}

		return cnt;
	}

	int numEnclaves(vector<vector<int>>& grid) {
		vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
		int answer = 0;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1 && visit[i][j] == false) {
					answer += check(grid, visit, i, j);
				}
			}
		}

		return answer;
	}
};