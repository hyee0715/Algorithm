class Solution {
public:
	void bfs(int a, int b, vector<vector<char>>& grid, vector<vector<bool>>& visit) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		queue<pair<int, int> > q;

		q.push({ a, b });
		visit[a][b] = true;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
				if (grid[nx][ny] == '1' && visit[nx][ny] == false) {
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		vector<vector<bool> > visit;
		vector<bool> temp(grid[0].size(), false);
		int answer = 0;

		for (int i = 0; i < grid.size(); i++) {
			visit.push_back(temp);
		}

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == '1' && visit[i][j] == false) {
					bfs(i, j, grid, visit);
					answer++;
				}
			}
		}

		return answer;
	}
};