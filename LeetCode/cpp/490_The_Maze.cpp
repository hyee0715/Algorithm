class Solution {
public:
	bool bfs(vector<vector<int>>& maze, vector<vector<bool>>& visit, vector<int>& start, vector<int>& destination) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		queue<pair<int, int>> q;
		q.push({ start[0], start[1] });
		visit[start[0]][start[1]] = true;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == destination[0] && y == destination[1]) {
				return true;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				while (nx >= 0 && ny >= 0 && nx < maze.size() && ny < maze[0].size() && maze[nx][ny] != 1) {
					nx += dx[i];
					ny += dy[i];
				}

				if (visit[nx - dx[i]][ny - dy[i]] == false) {
					visit[nx - dx[i]][ny - dy[i]] = true;
					q.push({ nx - dx[i], ny - dy[i] });
				}
			}
		}

		return false;
	}

	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		vector<vector<bool>> visit(maze.size(), vector<bool>(maze[0].size(), false));

		return bfs(maze, visit, start, destination);
	}
};